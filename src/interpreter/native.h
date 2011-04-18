#ifndef INTERPRETER_NATIVE_H
#define INTERPRETER_NATIVE_H

#include <pinocchio.h>

/* ======================================================================= */

Class NativeName_class;

struct NativeName {
	Header header;
	Symbol module;
	Symbol name;
};

/* ======================================================================= */

#ifndef DEBUG
#define NATIVE(module, name)\
    Object NM_##module##_##name( void ** pc ) {\
        Object * arg;\
        __asm("mov %%rbp, %0;": "=q"(arg));\
        arg += 2;\
        if (arg[0]->header.class != SmallInteger_class) {\
            printf("invalid arg: %p\n", arg);\
            exit(-1);\
        }

#else
#define NATIVE(module, name)\
    Object NM_##module##_##name( void ** pc ) {\
        printf("Calling "#module">>"#name"\n");
#endif

#define END_NATIVE\
	return;\
    }

#define INSTALL_NATIVE(module, name)\
    install_native( new_NativeName( L""#module, L""#name ), NM_##module##_##name )

#define ARGUMENT(index) arg[index]
#define NATIVE_RETURN(result) return (Object)result

/* ======================================================================= */

extern NativeName new_NativeName(const wchar_t*, const wchar_t*);

extern native lookup_native(NativeName name);
extern void install_native(NativeName,native);

extern void init_natives();

/* ======================================================================= */

#endif // INTERPRETER_NATIVE_H
