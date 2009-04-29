#include <bootstrap.h>
#include <primitives.h>
#include <system.h>
#include <ast.h>
#include <assert.h>

fools_object fools_system;

#define define_native(cls, name, native)\
    do_define_native(fools_system->cls, name, &native)

void inline do_define_native(native_class_object cls,
                          const char* name,
                          transfer_target native) {
    dict_at_put(cls->natives,
                symbol_known_to_the_vm(name),
                (object)make_native(native));
}

fools_object bootstrap() {
    fools_system                            = NEW(struct fools);
    fools_system->nil                       = make_nil();
    fools_system->empty = (array_object)make_object(1, (object)fools_system->nil);
    fools_system->empty->size               = make_number(0);
    fools_system->native                    = (object)make_native(&native);
 
    header(fools_system->native.pointer)    = fools_system->native;

    fools_system->symbols_known_to_the_vm   = make_array(17);

    fools_system->native_metaclass = (object)make_native(&with_native_class_lookup);

// currently broken.
//    fools_system->dict_class = make_native_class(2);
//    header(fools_system->dict_class->natives) = (object)fools_system->dict_class;
//    define_native(dict_class, "at:",                    prim_dict_at);
//    define_native(dict_class, "at:put:",                prim_dict_at_put);

    fools_system->ilist_class = make_native_class(3);
    define_native(ilist_class, "return:env:continue:",  ilist_continue_eval);
    define_native(ilist_class, "eval:",                 ilist_eval);
    define_native(ilist_class, "preEval:env:",          pre_eval_env);
    
    fools_system->iconst_class = make_native_class(2);
    define_native(iconst_class, "eval:",                iconst_eval);
    define_native(iconst_class, "preEval:env:",         pre_eval_env);

    fools_system->icall_class = make_native_class(3);
    define_native(icall_class, "eval:",                 icall_eval);
    define_native(icall_class, "invoke:env:",           icall_invoke_env);
    define_native(icall_class, "preEval:env:",          pre_eval_env);

    fools_system->iassign_class = make_native_class(2);
    define_native(iassign_class, "eval:",               iassign_eval);
    define_native(iassign_class, "preEval:env:",        pre_eval_env);

    fools_system->ivar_class = make_native_class(3);
    define_native(ivar_class, "eval:",                  ivar_eval);
    define_native(ivar_class, "assign:in:",             ivar_assign);
    define_native(ivar_class, "preEval:env:",           pre_eval_env);

    fools_system->icapture_class = make_native_class(1);
    define_native(icapture_class, "eval:",              icapture_eval);

    fools_system->icapture = (object)(instruction)make_icapture();

    fools_system->env_class = make_native_class(5);
    define_native(env_class, "fetch:from:",             env_fetch_from);
    define_native(env_class, "store:at:in:",            env_store_at_in);
    define_native(env_class, "subScope:",               env_subscope);
    define_native(env_class, "parent:",                 env_set_parent);
    define_native(env_class, "parent",                  env_parent);

    fools_system->iscope_metaclass = make_native_class(1);
    define_native(iscope_metaclass, "env:new:size:",    iscope_new);

    fools_system->iscope =
        (object)make_object(0, (object)fools_system->iscope_metaclass);

    fools_system->iscope_class = make_native_class(3);
    define_native(iscope_class, "eval:withArguments:",  iscoped_eval_arguments);
    define_native(iscope_class, "doEval:withArguments:",iscoped_eval);
    define_native(iscope_class, "scope",                iscoped_scope);

    fools_system->appcall_class = make_native_class(2);
    define_native(appcall_class, "eval:",               icall_eval);
    define_native(appcall_class, "invoke:env:",         appcall_invoke);


    return fools_system;
}
