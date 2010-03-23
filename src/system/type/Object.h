#ifndef TYPE_OBJECT_H
#define TYPE_OBJECT_H

#include <pinocchio.h>

/* ========================================================================= */

#define OBJECT_SIZE 0
#define OBJECT_VARS

/* ========================================================================= */

struct Type_Object_t {
    Object ivals[0]; 
};

CREATE_INITIALIZERS(Type_Object)
extern void inter_init_Type_Object();

/* ========================================================================= */

extern Object Object_instVarAt_(Object self, int index);
extern void Object_instVarAt_put_(Object self, int index, Object value);

/* ========================================================================= */

#endif // TYPE_OBJECT_H
