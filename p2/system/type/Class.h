#ifndef CLASS_H
#define CLASS_H

#include <pinocchio.h>

/* ========================================================================= */

extern Type_Class Metaclass;

/* ========================================================================= */

typedef enum Type_Tag {
    ARRAY   = 0,
    BYTES   = 1,
    CHAR    = 2,
    INT     = 3,
    LONG    = 4,
    OBJECT  = 5,
    WORDS   = 6,
} Type_Tag;

struct Type_Class_t {
    Object          type;
    Object          super;
    Type_Dictionary methods;
    Type_String     name;
    Object          cvars[];
};

CREATE_INITIALIZERS(Type_Class)

/* ========================================================================= */

extern Type_Class new_Class(Object superclass, Object type);
extern Type_Class new_Named_Class(Object superclass, const wchar_t* name,
                                  Object type);

/* ========================================================================= */

extern void Type_Class_dispatch(InlineCache * sender, Object self, Object class,
                    Object msg, Type_Array args);

extern void CNT_Class_super();

extern void print_Class(Object obj);

extern Object create_type(unsigned int size, Type_Tag tag);

/* ========================================================================= */

extern Object instantiate(Type_Class class);

/* ========================================================================= */

extern void assert_class(Object class);

/* ========================================================================= */

#endif // CLASS_H
