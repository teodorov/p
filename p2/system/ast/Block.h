#ifndef AST_BLOCK_H
#define AST_BLOCK_H

#include <pinocchio.h>

/* ======================================================================== */

struct AST_Block_t {
    Type_SmallInt   paramCount;
    Runtime_BlockContext     environment;
    Type_Array      body;
};

CREATE_INITIALIZERS(AST_Block)
extern AST_Block new_AST_Block(unsigned int paramCount, Type_Array body);

/* ======================================================================== */

extern void AST_Block_invoke(AST_Block block, Object self,
                      Object class, Type_Array args);
                      
/* ======================================================================== */

#endif // AST_BLOCK_H
