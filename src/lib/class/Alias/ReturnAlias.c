#include <lib/class/Alias/ReturnAlias.h>


Optr layout_Alias_ReturnAlias_Class_class;
Optr layout_Alias_ReturnAlias;

void init_Alias_PReturnAlias_layout() {
    layout_Alias_ReturnAlias_Class_class = (Optr)create_layout_with_vars(ObjectLayout_Class, 5);
    ((Array)layout_Alias_ReturnAlias_Class_class)->values[0] = slot_Kernel_Object_Object_Class_class_layout; // layout 
    ((Array)layout_Alias_ReturnAlias_Class_class)->values[1] = slot_Kernel_Object_Object_Class_class_superclass; // superclass 
    ((Array)layout_Alias_ReturnAlias_Class_class)->values[2] = slot_Kernel_Object_Object_Class_class_methods; // methods 
    ((Array)layout_Alias_ReturnAlias_Class_class)->values[3] = slot_Kernel_Object_Object_Class_class_name; // name 
    ((Array)layout_Alias_ReturnAlias_Class_class)->values[4] = slot_Kernel_Object_Object_Class_class_package; // package 
    
    Symbol  SMB_ReturnAlias = new_Symbol(L"ReturnAlias");
    layout_Alias_ReturnAlias = (Optr)create_layout_with_vars(ObjectLayout_Class, 3);
    ((Array)layout_Alias_ReturnAlias)->values[0] = slot_Alias_Alias_origin; // origin 
    ((Array)layout_Alias_ReturnAlias)->values[1] = slot_Alias_Alias_context; // context 
    ((Array)layout_Alias_ReturnAlias)->values[2] = slot_Alias_Alias_value; // value 
    Alias_ReturnAlias_Class = (Class)new_Class(Alias_MethodAlias_Class, layout_Alias_ReturnAlias_Class_class);
    Alias_ReturnAlias_Class->layout = layout_Alias_ReturnAlias;
    Alias_ReturnAlias_Class->name = SMB_ReturnAlias;
    
}

void init_Alias_PReturnAlias_methods() {
    
}