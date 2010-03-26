#ifndef PLUGIN_H
#define PLUGIN_H 

#include <pinocchio.h>

/* ========================================================================= */

extern Collection_Dictionary create_plugin();
extern Collection_Dictionary add_plugin(const wchar_t * name);
extern void store_native(Collection_Dictionary plugin, Type_Symbol selector, native code);

extern void init_plugin();

/* ========================================================================= */
#endif //PLUGIN_H