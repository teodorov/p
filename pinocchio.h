#ifndef PINOCCHIO_H
#define PINOCCHIO_H

#include <stdlib.h>
#include <setjmp.h>
#include <errno.h>
#include <stdio.h>
#include <wchar.h>

#include <gc.h>

/* ======================================================================= */

typedef unsigned long               uns_int;

typedef struct Object*              Object;
typedef struct Behavior*            Behavior;
typedef struct Class*               Class;
typedef struct Slot*                Slot;
typedef struct Layout*              Layout;
typedef struct Metaclass*           Metaclass;
typedef struct Dictionary*          Dictionary;
typedef struct SmallInteger*        SmallInteger;
typedef struct Array*               Array;
typedef struct Symbol*              Symbol;
typedef struct String*              String;
typedef struct Dictionary*          SymbolTable;
typedef struct Bucket*              Bucket;
typedef struct BucketArray*         BucketArray;
typedef struct Method*              Method;
typedef struct MethodClosure*       MethodClosure;

typedef struct Context*             Context;
typedef struct MethodContext*       MethodContext;
typedef struct BlockContext*        BlockContext;
typedef struct Thread*              Thread;
typedef struct Raw*                 Raw;
typedef struct RawArray*            RawArray;

typedef Dictionary                  MethodDictionary;

struct Header {
    uns_int     variable: 1;
    uns_int     raw:      1;
    uns_int     stack:    1;
    uns_int     base: sizeof(uns_int) * 8 - 3;
    Behavior    class;
};

struct VariableHeader {
    uns_int     variable: 1;
    uns_int     raw:      1;
    uns_int     stack:    1;
    uns_int     base: sizeof(uns_int) * 8 - 3;
    Behavior    class;
    uns_int     size;
};

typedef struct Header               Header;
typedef struct VariableHeader       VariableHeader;
typedef struct StackHeader          StackHeader;
typedef struct VariableStackHeader  VariableStackHeader;

/* ======================================================================= */

#include <assert.h>
#include <kernel/string/utility.h>
#include <kernel/object/object.h>
#include <kernel/object/raw.h>
#include <kernel/object/rawarray.h>
#include <kernel/object/class.h>
#include <kernel/structure/slot/slot.h>
#include <kernel/structure/layout.h>
#include <kernel/string/symbol.h>
#include <kernel/string/string.h>
#include <kernel/number/smallinteger.h>
#include <kernel/collection/dictionary.h>
#include <kernel/collection/bucket.h>
#include <kernel/collection/array.h>
#include <kernel/behavior/methoddictionary.h>
#include <kernel/behavior/method.h>
#include <kernel/behavior/methodclosure.h>

#include <kernel/interpreter/context.h>
#include <kernel/interpreter/thread.h>

#include <interpreter/opcodes.h>

/* ======================================================================= */

#endif // PINOCCHIO_H
