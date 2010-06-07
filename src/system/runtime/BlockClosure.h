#ifndef RUNTIME_CLOSURE_H
#define RUNTIME_CLOSURE_H

#include <pinocchio.h>

/* ========================================================================= */

struct Runtime_BlockClosure_t {
    AST_Block            code;
    Runtime_BlockContext context;
};

extern void post_init_Runtime_BlockClosure();
extern Runtime_BlockClosure new_Runtime_BlockClosure(AST_Block code,
                                           Runtime_BlockContext context);

/* ========================================================================= */

extern void Runtime_BlockClosure_apply(Runtime_BlockClosure closure, uns_int argc);
extern void apply(Object closure, uns_int argc);

/* ========================================================================= */

#define METHOD(fName, paramCount, localCount, numStatements)\
Runtime_MethodClosure fName() {\
    AST_Method body          = new_AST_Method(paramCount, localCount, numStatements);\
    Runtime_MethodClosure method = new_Runtime_MethodClosure(body, (Class)Nil);\
    method->info             = new_raw_AST_Info();\
    method->info->sourceFile = new_String_from_charp(__FILE__);\
    method->info->name       = new_String_from_charp(__FUNCTION__);\
    method->info->line       = new_SmallInt(__LINE__);\
    unsigned int _st_count   = 0;

#define ADD_STATEMENT(value)\
    body->body[_st_count++] = (Object)(value);

/* ========================================================================= */

Runtime_BlockContext  activation_from_native(uns_int argc);

/* ========================================================================= */

#endif // RUNTIME_CLOSURE_H
