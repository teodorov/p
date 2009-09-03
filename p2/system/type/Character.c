#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <setjmp.h>
#include <wchar.h>
#include <pinocchio.h>
#include <system/type/Character.h>

Type_Class * Character_Class;

/* ========================================================================== */

Type_Character * 
new_Character(wchar_t value)
{
    Type_Character * result = NEW(Type_Character);
    HEADER(result)          = (Object)Character_Class;
    result->value           = value;
    // TODO add character table here for caching
    return result;
}


void Character_toString()
{
    // TODO implement
}

void Character_toSymbol()
{
    // TODO implement
}

void Character_toSmallInt()
{
    // TODO implement
}


void pre_initialize_Character()
{
    Character_Class = new_Named_Class((Object)Object_Class, L"Character");
}

void post_initialize_Character()
{
    // TODO install methods 
}