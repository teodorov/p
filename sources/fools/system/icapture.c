#include <system.h>
#include <thread.h>

// icapture>>eval:
static void inline icapture_eval() {
    context_object context = get_context();
    debug("icapture>>eval\n");
    return_from_context(context, context->env);
    debug("ret>>icapture>>eval %p\n", context->env.env);
}

void icapture_dispatch() {
    dispatch_header(context, selector);
    if_selector(selector, EVAL, icapture_eval);
    doesnotunderstand("icapture", selector);
}

// Object creation
icapture_object make_icapture() {
    new_instance(icapture);
    return result;
}
