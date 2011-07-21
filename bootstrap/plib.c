#include <stdlib.h>
#include <stdio.h>
#include <gc/gc.h>
#include <signal.h>
#include <malloc.h>
#include <string.h>

extern long true[];
extern long false[];
extern long SmallInteger[];

#define ENC_INT(v)  ((long*)(((v) << 1) + 1))
#define DEC_INT(v)  ((long)(v) >> 1)
#define IS_INT(v)   ((char)(long)(v) & 1)
#define ARE_INTS(x, y) ((char)(x) & (char)(y) & (char)1)

extern void * fib(long* i);
long plus(long left, long right);
long minus(long left, long right);
long * smaller(long left, long right);

long cache_and_call()
{
    // Fetch the calling instruction pointer (stack-stored ip)
    __asm("mov 0(%rsp), %eax");
    // Calculate the offset of the actual code pointer
    __asm("mov %r10, %rdx");
    __asm("sub %eax, %edx");
    // Overwrite the 4-byte call-target offset with the method
    __asm("movl %edx, -4(%eax)");
    // Calculate the location of the literal in the frame
    __asm("lea -5(%eax), %edx");
    __asm("movl -9(%eax), %eax");
    __asm("cltq");
    __asm("add %rax, %rdx");
    // Calculate the class
    // If tagged integer, store the SmallInteger class
    __asm("bt $0, %rdi");
    __asm("jae not_tagged");
    __asm("mov %0, %%rax"::"r"(SmallInteger));
    __asm("mov %rax, (%rdx)");
    // __asm("int3");
    __asm("jmp *%r10");
    // If not tagged, store the class of the receiver
__asm("not_tagged:");
    __asm("mov -8(%rdi), %rdx");
    __asm("mov %rdx, (%rax)");
    __asm("jmp *%r10");
}

void invoke_error(long msg, void* receiver)
{
    printf("Lookup of msg %ld failed on %p\n", msg, receiver);
    __asm("int3");
}

void invoke() {
    __asm("cmp $0x611b38, %rax");
    __asm("mov $plus, %r10");
    __asm("je cache_and_call");

    __asm("cmp $21, %rax");
    __asm("mov $minus, %r10");
    __asm("je cache_and_call");

    __asm("cmp $31, %rax");
    __asm("mov $fib, %r10");
    __asm("je cache_and_call");

    __asm("cmp $11, %rax");
    __asm("mov $smaller, %r10");
    __asm("je cache_and_call");

    __asm("cmp $51, %rax");
    __asm("mov $fibSend, %r10");
    __asm("je cache_and_call");

    __asm("mov %rdi, %rsi");
    __asm("mov %rax, %rdi");
    __asm("call invoke_error");
}

long * closureNew(int size) {
    long * c = GC_MALLOC( sizeof(long*) + size*sizeof(long*) );
    c[0] = 77;
    printf( "- new closure at: %p\n", c+1 );
    return c + 1;
}

long * remoteArrayNew(int size) {
    long * c = GC_MALLOC( sizeof(long*) + size*sizeof(long*) );
    c[0] = 33;
    printf( "- new array at: %p\n", c+1 );
    return c + 1;
}

void closureValue() {
    //if its not a closure then jmp to invoke
    __asm("bt $0, %rdi");
    __asm("jnae invoke");
    __asm("cmp $77, -0x8(%rdi)");
    __asm("jne invoke");
    //load code-pointer from the closure-object
    __asm("mov (%rdi), %rax");
    __asm("jmpq *%rax");
}

long plus(long left, long right)
{
//    printf( "plus: %p + %p\n", left, right );
    if (ARE_INTS(left, right))
        return (left ^ 1) + right;
}

long minus(long left, long right)
{
//    printf( "minus: %p - %p\n", left, right );
    if (ARE_INTS(left, right))
        return (left - right) | 1;
}

long * smaller(long left, long right)
{
    // printf( "smaller: %d < %d\n", left, right );
    if (ARE_INTS(left, right)) {
    // we don't need to remove the tag since it will end up being the same order.
        // printf( "smaller: %d < %d\n", left, right );
        return left < right ? true : false;
    }
}

extern void* Kernel_String_Symbol[];

void* get_class(void* object[]) {
    return object[-2];
}

extern void* Kernel_Object_Metaclass[];

void print_symbol(void* object[]) {
    long size = (long)object[-3];
    char buffer[size+1];
    strncpy(buffer, (char*)object, size);
    buffer[size] = 0;
    printf("%s", buffer);
}

void* print_class_name(void* object[]) {
    if (get_class(object) == Kernel_Object_Metaclass) {
        print_symbol(((void**)object[4])[4]);
        printf(" class");
    } else {
        print_symbol(object[4]);
    }
}

typedef struct header {
    unsigned char base:     8;
    unsigned char variable: 1;
    unsigned char bytes:    1;
    unsigned char mutable:  1;
    unsigned char gcmark:   1;
    unsigned long hash:     sizeof(unsigned long) * 8 - 12;
} header;

header get_header(header * object) {
    return object[-1];
}

void print_object(void* object[]) {
    
    if (IS_INT(object)) {
        printf(" %ld\n", DEC_INT(object));
        return;
    }

    printf("printing object: %p\n", object);
    header h = get_header((header*)object);
    if (h.variable || h.bytes) {
        printf("size: %lu\n", (long)object[-3]);
    }
    printf(" header: (base: %i var: %i bytes: %i mutable: %i gcmark: %i hash: %lu)\n", 
                      h.base, h.variable, h.bytes, h.mutable, h.gcmark, (unsigned long)h.hash);

    if (Kernel_String_Symbol == get_class(object)) {
        printf(" #'");
        print_symbol(object);
        printf("' (%p)\n", object);
        return;
    }

    printf(" is a: ");
    print_class_name(get_class(object));
    printf("\n");
}

typedef void ** MethodDictionary;
typedef long    SmallInt;
typedef void ** Layout;
typedef void ** Object;

typedef struct Behavior* Behavior;

struct Behavior {
    MethodDictionary    methods;
    Behavior            superclass;
    SmallInt            instanceHeader;
    Layout              layout;
};

Object* basicNew(Behavior b) {
    printf("Behavior: %p\n", b);
    long _h = b->instanceHeader >> 1;
    printf("header: %li\n", _h);
    header h = *(header*)&_h;
    Object* result;
    if (h.variable) {
        result = GC_MALLOC(sizeof(void**) * (h.base + 3)) + 3;
        result[-3] = (Object)0;
    } else {
        printf("Allocating object of size: %u\n", h.base);
        result = GC_MALLOC(sizeof(void**) * (h.base + 2)) + 2;
    }
    result[-2] = (Object)b;
    result[-1] = (Object)_h;
    return result;
}

Object* basicNew_(Behavior b, long tagged_size) {
    long h = b->instanceHeader;
    long base = (h >> 1) & ((2 << 8) - 1);
    long extra = tagged_size >> 1;
    Object* result;
    if (h & (1 << 9)) {
        result = GC_MALLOC(sizeof(void**) * (base + 3 + extra)) + 3;
        result[-3] = (Object)extra;
    } else {
        // should not happen
        exit(-1);
    }
    result[-2] = (Object)b;
    result[-1] = (Object)(h >> 1);
    return result;
}
