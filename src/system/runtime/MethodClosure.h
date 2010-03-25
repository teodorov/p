#ifndef RUNTIME_METHODCLOSURE_H
#define RUNTIME_METHODCLOSURE_H

#include <pinocchio.h>

/* ========================================================================= */

#define RUNTIME_METHODCLOSURE_SIZE 4
#define RUNTIME_METHODCLOSURE_VARS L"code", L"info", L"selector", L"host"

/* ========================================================================= */

struct Runtime_MethodClosure_t {
    AST_Method          code;
    AST_Info            info;
    Object              selector;
    Type_Class          host;
};

CREATE_INITIALIZERS(Runtime_MethodClosure)
extern Runtime_MethodClosure new_Runtime_MethodClosure(AST_Method code,
                                                       Type_Class host);

/* ========================================================================= */

extern void Runtime_MethodClosure_invoke(Runtime_MethodClosure closure, Object self,
                                         uns_int argc);

/* ========================================================================= */

#endif // RUNTIME_METHODCLOSURE_H
