#include <stdio.h>
#include <stdlib.h>
#include "settings.h"

#define SMALLER (void*)11
#define MINUS (void*)21
#define FIB (void*)31
#define PLUS (void*)41
#define FIB_SEND (void*)51

extern void * METHOD_NAME();
extern void * blockTest();
extern void * arrayNew();
extern long * intNew();

long p_1[3];
long p_2[3];
long p_true[2];
long p_false[2];

long * true;
long * false;

int init() {
    p_1[1] = 66; 
    p_1[2] = 1;

    p_2[1] = 66; 
    p_2[2] = 2;

    true  = p_true + 2;
    false = p_false + 2;
}

int main(int argc, char**argv)
{
    init();
 
    void * method[] = {(void*)22,(void*)123456,(void*)234561,(void*)345612,(void*)456123,(void*)561234,(void*)PLUS,(void*)MINUS,(void*)SMALLER,(void*)FIB,(void*)FIB_SEND, (void*)66 };
 
    int offset = *(int*)&((unsigned char*)&METHOD_NAME)[METHOD_OFFSET-4];
    void** method_pointer = (void**)&(((unsigned char*)&METHOD_NAME)[offset+METHOD_OFFSET]);    
    
    // printf("of: %d\n", offset);
 
    *method_pointer = method+1;
 
    long * self = intNew();
    self[0] = argc > 1 ? atoi(argv[1]) : 0;
 
    /*
    printf("address: %p\n", method_pointer);
    printf("self: %ld\n", self[0]);
    
    printf("false: %p\n", p_false + 2);
    */
    
    long self_type = self[-1];
    long * result;
    __asm("mov %0, %%rdi"::"r"(self));
    __asm("mov %0, %%rax"::"r"(self_type));
    __asm(METHOD_CALL);
    __asm("mov %%rax, %0":"=r"(result));
 
    
    //printf("result: %p\n",result);
    printf("result: %li\n",result[0]);
    return 0;
}
