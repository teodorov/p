#include <lib/class/PEG/OptionalExpression.h>


Optr layout_PEG_OptionalExpression_Class_class;
Optr slot_PEG_OptionalExpression_child;
Optr layout_PEG_OptionalExpression;


static void init_SMB_initialize_() {
    Symbol SMB_initialize_ = new_Symbol(L"initialize:");
    Variable VAR_expression_0_0 = new_Variable_named(L"expression", 0);
    Array PArray19884 = new_Array_with(1, (Optr)VAR_expression_0_0);
    Symbol SMB_asChildParser = new_Symbol(L"asChildParser");
    // asChildParser. 
    Send PSend19887 = new_Send((Optr)VAR_expression_0_0, SMB_asChildParser, 0);
    Assign PAssign19886 = new_Assign((Optr)slot_PEG_OptionalExpression_child, (Optr)PSend19887);
    Array PThreadedCode19885 = instantiate_Array_with(ThreadedCode_Class, 0, 9, (Optr)&t_push1, (Optr)PAssign19886, (Optr)&t_push_variable, (Optr)VAR_expression_0_0, (Optr)&t_send0, (Optr)PSend19887, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_method_return_self);
    Method PMethod19883 = new_Method_with(PArray19884, empty_Array, empty_Array, PThreadedCode19885, 2, PAssign19886, self);
    
    MethodClosure MC_SMB_initialize_ = new_MethodClosure((Method)PMethod19883, PEG_OptionalExpression_Class);
    store_method(PEG_OptionalExpression_Class, SMB_initialize_, MC_SMB_initialize_);
}


static void init_SMB_optional() {
    Symbol SMB_optional = new_Symbol(L"optional");
    Array PThreadedCode19889 = instantiate_Array_with(ThreadedCode_Class, 0, 1, (Optr)&t_method_return_self);
    Method PMethod19888 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode19889, 1, self);
    
    MethodClosure MC_SMB_optional = new_MethodClosure((Method)PMethod19888, PEG_OptionalExpression_Class);
    store_method(PEG_OptionalExpression_Class, SMB_optional, MC_SMB_optional);
}


static void init_SMB_parseOn_() {
    Symbol SMB_parseOn_ = new_Symbol(L"parseOn:");
    Variable VAR_input_0_0 = new_Variable_named(L"input", 0);
    Array PArray19891 = new_Array_with(1, (Optr)VAR_input_0_0);
    Variable VAR__return__1_0 = new_Variable_named(L"_return_", 1);
    Array PArray19894 = new_Array_with(1, (Optr)VAR__return__1_0);
    // parseOn:. 
    Send PSend19896 = new_Send((Optr)slot_PEG_OptionalExpression_child, SMB_parseOn_, 1, (Optr)VAR_input_0_0);
    Symbol SMB_ifFalse_ = new_Symbol(L"ifFalse:");
    Symbol SMB_stack = new_Symbol(L"stack");
    // stack. 
    Send PSend19900 = new_Send((Optr)VAR_input_0_0, SMB_stack, 0);
    Symbol SMB_push_ = new_Symbol(L"push:");
    // push:. 
    Send PSend19901 = new_Send((Optr)PSend19900, SMB_push_, 1, (Optr)PEGFailedOptionalResult_classReference);
    Symbol SMB_escape_ = new_Symbol(L"escape:");
    // escape:. 
    Send PSend19902 = new_Send((Optr)VAR__return__1_0, SMB_escape_, 1, (Optr)true_Const);
    Array PThreadedCode19899 = instantiate_Array_with(ThreadedCode_Class, 0, 15, (Optr)&t_push_variable, (Optr)VAR_input_0_0, (Optr)&t_send0, (Optr)PSend19900, (Optr)&t_push_class_reference, (Optr)PEGFailedOptionalResult_classReference, (Optr)&t_send1, (Optr)PSend19901, (Optr)&t_zap, (Optr)&t_push_variable, (Optr)VAR__return__1_0, (Optr)&t_push_true, (Optr)&t_send1, (Optr)PSend19902, (Optr)&t_block_return);
    Block PBlock19898 = new_Block_with(empty_Array, empty_Array, PThreadedCode19899, 2, PSend19901, PSend19902);
    // ifFalse:. 
    Send PSend19897 = new_Send((Optr)PSend19896, SMB_ifFalse_, 1, (Optr)PBlock19898);
    // stack. 
    Send PSend19903 = new_Send((Optr)VAR_input_0_0, SMB_stack, 0);
    // stack. 
    Send PSend19904 = new_Send((Optr)VAR_input_0_0, SMB_stack, 0);
    Symbol SMB_peek = new_Symbol(L"peek");
    // peek. 
    Send PSend19905 = new_Send((Optr)PSend19904, SMB_peek, 0);
    Symbol SMB_on_ = new_Symbol(L"on:");
    // on:. 
    Send PSend19906 = new_Send((Optr)PEGSucceededOptionalResult_classReference, SMB_on_, 1, (Optr)PSend19905);
    Symbol SMB_poke_ = new_Symbol(L"poke:");
    // poke:. 
    Send PSend19907 = new_Send((Optr)PSend19903, SMB_poke_, 1, (Optr)PSend19906);
    Array PThreadedCode19895 = instantiate_Array_with(ThreadedCode_Class, 0, 28, (Optr)&t_push_slot, (Optr)slot_PEG_OptionalExpression_child, (Optr)&t_push_variable, (Optr)VAR_input_0_0, (Optr)&t_send1, (Optr)PSend19896, (Optr)&t_send_ifFalse_, (Optr)PSend19897, (Optr)PBlock19898, (Optr)&t_zap, (Optr)&t_push_variable, (Optr)VAR_input_0_0, (Optr)&t_send0, (Optr)PSend19903, (Optr)&t_push_class_reference, (Optr)PEGSucceededOptionalResult_classReference, (Optr)&t_push_variable, (Optr)VAR_input_0_0, (Optr)&t_send0, (Optr)PSend19904, (Optr)&t_send0, (Optr)PSend19905, (Optr)&t_send1, (Optr)PSend19906, (Optr)&t_send1, (Optr)PSend19907, (Optr)&t_zap, (Optr)&t_method_return_true);
    Block PBlock19893 = new_Block_with(PArray19894, empty_Array, PThreadedCode19895, 3, PSend19897, PSend19907, true_Const);
    // on:. 
    Send PSend19908 = new_Send((Optr)PContinue_classReference, SMB_on_, 1, (Optr)PBlock19893);
    Array PThreadedCode19892 = instantiate_Array_with(ThreadedCode_Class, 0, 7, (Optr)&t_push_class_reference, (Optr)PContinue_classReference, (Optr)&t_push_closure, (Optr)PBlock19893, (Optr)&t_send1, (Optr)PSend19908, (Optr)&t_method_return);
    Method PMethod19890 = new_Method_with(PArray19891, empty_Array, empty_Array, PThreadedCode19892, 1, PSend19908);
    
    MethodClosure MC_SMB_parseOn_ = new_MethodClosure((Method)PMethod19890, PEG_OptionalExpression_Class);
    store_method(PEG_OptionalExpression_Class, SMB_parseOn_, MC_SMB_parseOn_);
}


static void init_SMB_omitMatch_() {
    Symbol SMB_omitMatch_ = new_Symbol(L"omitMatch:");
    Variable VAR_input_0_0 = new_Variable_named(L"input", 0);
    Array PArray19910 = new_Array_with(1, (Optr)VAR_input_0_0);
    // omitMatch:. 
    Send PSend19912 = new_Send((Optr)slot_PEG_OptionalExpression_child, SMB_omitMatch_, 1, (Optr)VAR_input_0_0);
    Array PThreadedCode19911 = instantiate_Array_with(ThreadedCode_Class, 0, 8, (Optr)&t_push_slot, (Optr)slot_PEG_OptionalExpression_child, (Optr)&t_push_variable, (Optr)VAR_input_0_0, (Optr)&t_send1, (Optr)PSend19912, (Optr)&t_zap, (Optr)&t_method_return_true);
    Method PMethod19909 = new_Method_with(PArray19910, empty_Array, empty_Array, PThreadedCode19911, 2, PSend19912, true_Const);
    
    MethodClosure MC_SMB_omitMatch_ = new_MethodClosure((Method)PMethod19909, PEG_OptionalExpression_Class);
    store_method(PEG_OptionalExpression_Class, SMB_omitMatch_, MC_SMB_omitMatch_);
}

void init_PEG_PEGOptionalExpression_layout() {
    layout_PEG_OptionalExpression_Class_class = (Optr)create_layout_with_vars(ObjectLayout_Class, 5);
    ((Array)layout_PEG_OptionalExpression_Class_class)->values[0] = slot_Kernel_Object_Object_Class_class_layout; // layout 
    ((Array)layout_PEG_OptionalExpression_Class_class)->values[1] = slot_Kernel_Object_Object_Class_class_superclass; // superclass 
    ((Array)layout_PEG_OptionalExpression_Class_class)->values[2] = slot_Kernel_Object_Object_Class_class_methods; // methods 
    ((Array)layout_PEG_OptionalExpression_Class_class)->values[3] = slot_Kernel_Object_Object_Class_class_name; // name 
    ((Array)layout_PEG_OptionalExpression_Class_class)->values[4] = slot_Kernel_Object_Object_Class_class_package; // package 
    
    Symbol  SMB_OptionalExpression = new_Symbol(L"OptionalExpression");
    slot_PEG_OptionalExpression_child = (Optr)new_Slot(0, L"child");
    layout_PEG_OptionalExpression = (Optr)create_layout_with_vars(ObjectLayout_Class, 1);
    ((Array)layout_PEG_OptionalExpression)->values[0] = slot_PEG_OptionalExpression_child; // child 
    PEG_OptionalExpression_Class = (Class)new_Class(PEG_Expression_Class, layout_PEG_OptionalExpression_Class_class);
    PEG_OptionalExpression_Class->layout = layout_PEG_OptionalExpression;
    PEG_OptionalExpression_Class->name = SMB_OptionalExpression;
    
}

void init_PEG_PEGOptionalExpression_methods() {
    init_SMB_initialize_();
    init_SMB_optional();
    init_SMB_parseOn_();
    init_SMB_omitMatch_();
    
}