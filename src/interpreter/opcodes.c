#include <pinocchio.h>
#include <alloca.h>

/* ======================================================================= */

#define OPCODE_DECLS\
    char method_context( Method method, Object arg[] ) {

#define OPCODE_HEAD\
    if( arg == NULL ) {\

#define OPCODE_BODY\
	return 0;\
    }\
    void ** pc = (void**)method->code->data;\
    Object * local;\
    GO_NEXT();

#define OPCODE_EVALUATION

#define OPCODE_END\
    }

#define INSTALL_OPCODE(name)\
    op_##name = &&label_##name;

/* ======================================================================= */

#define GO_NEXT() goto **GET_PC()

#define SET_PC(value) pc = value
#define GET_PC() pc

#define SELF() arg[0]

#define FETCH(type, index)\
    (type)(*(index))

#define OBJECT(index) ((Object)index)

#define OPCODE(name)\
    label_##name:

#define END_OPCODE GO_NEXT();

#define UNS_INT_OPERAND(idx)\
    FETCH(uns_int, GET_PC() + idx)

#define INT_OPERAND(idx)\
    FETCH(long, GET_PC() + idx)

#define OBJECT_OPERAND(idx)\
    OBJECT(FETCH(uns_int, GET_PC() + idx))

#define LOAD(idx)\
    local[idx]

#define STORE(idx, object)\
    local[idx] = object

#define JUMP(offset)\
    SET_PC(GET_PC() + offset);

#define RETURN() return 0;
#define SET_RETURN(value) arg[0] = (value)

#define READ_FIELD(index) SELF()->field[index]
#define WRITE_FIELD(index, value) SELF()->field[index] = value
#define CALL_NATIVE(function) ((native)function)(arg)

#define CALL_METHOD(selector, arg_offset)\
    next_method = lookup(local[arg_offset], selector);\
    return_code = method_context( next_method->method, &local[arg_offset]);\
    if ( return_code != 0 ) {\
	return return_code;\
    }

/* ======================================================================= */

#define DECLARE_OPCODE(name) void * op_##name; 

/* ======================================================================= */



DECLARE_OPCODE(allocate_locals)
DECLARE_OPCODE(block_return)
DECLARE_OPCODE(cache_send)
DECLARE_OPCODE(exit)
DECLARE_OPCODE(iffalse_iftrue)
DECLARE_OPCODE(iftrue_iffalse)
DECLARE_OPCODE(jump)
DECLARE_OPCODE(load_constant)
DECLARE_OPCODE(lookup_native)
DECLARE_OPCODE(move)
DECLARE_OPCODE(poly_send)
DECLARE_OPCODE(return)
DECLARE_OPCODE(return_self)
DECLARE_OPCODE(self)
DECLARE_OPCODE(send)
DECLARE_OPCODE(slot_read)
DECLARE_OPCODE(slot_write)
DECLARE_OPCODE(try_native)

OPCODE_DECLS

uns_int target;
uns_int origin;
uns_int idx;
uns_int offset;
uns_int size;
long    address;
Symbol  selector;
Object  value;
NativeName name;
Raw function;
native native_function;
MethodClosure next_method;
char return_code;

OPCODE_HEAD

INSTALL_OPCODE(allocate_locals)
INSTALL_OPCODE(block_return)
INSTALL_OPCODE(cache_send)
INSTALL_OPCODE(exit)
INSTALL_OPCODE(iffalse_iftrue)
INSTALL_OPCODE(iftrue_iffalse)
INSTALL_OPCODE(jump)
INSTALL_OPCODE(load_constant)
INSTALL_OPCODE(lookup_native)
INSTALL_OPCODE(move)
INSTALL_OPCODE(poly_send)
INSTALL_OPCODE(return)
INSTALL_OPCODE(return_self)
INSTALL_OPCODE(self)
INSTALL_OPCODE(send)
INSTALL_OPCODE(slot_read)
INSTALL_OPCODE(slot_write)
INSTALL_OPCODE(try_native)

OPCODE_BODY

OPCODE(allocate_locals)
    size = UNS_INT_OPERAND(1);
    local = alloca( size * sizeof(Object*) );
    JUMP(2);
END_OPCODE


OPCODE(self)
    target = UNS_INT_OPERAND(1);
    value  = SELF();
    STORE(target, value);
    JUMP(2);
END_OPCODE

OPCODE(move)
    origin = UNS_INT_OPERAND(2);
    target = UNS_INT_OPERAND(1);
    value  = LOAD(origin);
    STORE(target, value);
    JUMP(3);
END_OPCODE

OPCODE(load_constant)
    target = UNS_INT_OPERAND(1);
    value  = OBJECT_OPERAND(2);
    STORE(target, value);
    JUMP(3);
END_OPCODE

OPCODE(slot_read)
    target        = UNS_INT_OPERAND(1);
    uns_int field = UNS_INT_OPERAND(2);
    value         = READ_FIELD(field);
    STORE(target, value);
    JUMP(3);
END_OPCODE

OPCODE(slot_write)
    origin = UNS_INT_OPERAND(1);
    idx    = UNS_INT_OPERAND(2);
    value  = LOAD(origin);
    WRITE_FIELD(idx, value);
    JUMP(3);
END_OPCODE

OPCODE(send)
    offset   = UNS_INT_OPERAND(1);
    selector = (Symbol)OBJECT_OPERAND(2);
    JUMP(3);
    CALL_METHOD(selector, offset);
END_OPCODE

OPCODE(cache_send)
    offset   = UNS_INT_OPERAND(1);
    selector = (Symbol)OBJECT_OPERAND(2);
    JUMP(3);
    CALL_METHOD(selector, offset);
END_OPCODE

OPCODE(poly_send)
    offset   = UNS_INT_OPERAND(1);
    selector = (Symbol)OBJECT_OPERAND(2);
    JUMP(3);
    CALL_METHOD(selector, offset);
END_OPCODE

OPCODE(return)
    origin  = UNS_INT_OPERAND(1);
    value   = LOAD(origin);
    SET_RETURN(value);
    RETURN();
END_OPCODE

OPCODE(return_self)
    RETURN();
END_OPCODE

OPCODE(block_return)
    origin  = UNS_INT_OPERAND(1);
    value   = LOAD(origin);
    SET_RETURN(value);
    RETURN();
END_OPCODE

OPCODE(iftrue_iffalse)
    origin = UNS_INT_OPERAND(1);
    value  = LOAD(origin);
    if (value == false) {
        address = INT_OPERAND(2);
        JUMP(address);
    }
    if (value != true) {
        address = INT_OPERAND(3);
        JUMP(address);
    }
    JUMP(4);
END_OPCODE

OPCODE(iffalse_iftrue)
    origin = UNS_INT_OPERAND(1);
    value  = LOAD(origin);
    if (value  == true) {
        address = INT_OPERAND(2);
        JUMP(target);
    }
    if (value  != false) {
        address = INT_OPERAND(3);
        JUMP(address);
    }
    JUMP(4);
END_OPCODE

OPCODE(jump)
    address = INT_OPERAND(1);
    JUMP(address);
END_OPCODE

/*
OPCODE(capture)
    Block block = (Block)OBJECT_OPERAND(1);
    target      = UNS_INT_OPERAND(2);
    value       = (Object)new_BlockClosure(CONTEXT(), block);
    STORE(target, value);
    JUMP(3);
END_OPCODE;
*/

OPCODE(lookup_native)
        printf("search native: \n");
    name = (NativeName)OBJECT_OPERAND(1);
    native_function = lookup_native(name);
    if (native_function) {
        printf("Found native: %p\n",native_function);
        *GET_PC()     = OP(try_native);
        *(GET_PC()+1) = new_Raw((void**)native_function);
        if (!CALL_NATIVE(native_function)) {
	    RETURN();
	}
        JUMP(2);
    } else {
        *GET_PC()     = OP(jump);
        *(GET_PC()+1) = (void**)2;
        JUMP(2);
    }
END_OPCODE

OPCODE(try_native)
    function = (Raw)OBJECT_OPERAND(1);
    if (!CALL_NATIVE(function->data)) {
	RETURN();
    }
    JUMP(2);
END_OPCODE

OPCODE(exit)
    return -1;
END_OPCODE

OPCODE_END
