#include <model.h>
#include <bootstrap.h>
#include <thread.h>
#include <system/type/array.h>

object_object make_object(int size, object interpreter) {
    object_object result  = NEW_ARRAYED(object_object, object, size);
    header(result)        = interpreter;
    int i;
    for (i = 0; i < size; i++) {
        object_at_put(result, i, (object)woodstock->nil);
    }
    return result;
}

native_object make_native(transfer_target native) {
    // Natives don't need a header, so we just allocate what we need.
    native_object result    = (native_object)PALLOC(sizeof(struct native));
    result->target          = (object)native;
    return result;
}

native_class_object make_native_class(object header, transfer_target cdisp) {
    native_class_object result  = NEW(struct native_class);
    header(result)              = header;
    result->cdisp               = (object)cdisp;
    return result;
}

// Accessors

transfer_target inline native_target(native_object native) {
    return native->target.target;
}
