#include <stdlib.h>
#include <stdio.h>
#include <system/runtime/MethodContext.h>

/* ========================================================================= */

Type_Class Runtime_MethodContext_Class;

/* ========================================================================= */

void pre_init_Runtime_MethodContext()
{
    Runtime_MethodContext_Class = new_Named_Class((Object)Type_Object_Class,
                                                  L"Runtime_MethodContext",
                                                  create_object_tag(RUNTIME_METHODCONTEXT));
}

/* ========================================================================= */

Runtime_MethodContext new_Runtime_MethodContext(Runtime_MethodClosure closure,
                                            Object self, Object class,
                                            Type_Array values) {
    NEW_OBJECT(Runtime_MethodContext);
    result->closure         = closure;
    result->pc              = 0;
    result->values          = values;
    result->home_context    = result;
    result->parent          = current_env();
    result->class           = class;
    result->self            = self;
    return result;
}


/* ========================================================================= */

void post_init_Runtime_MethodContext()
{

}
