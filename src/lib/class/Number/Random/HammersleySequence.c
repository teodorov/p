#include <lib/class/Number/Random/HammersleySequence.h>


Optr layout_Number_Random_HammersleySequence_Class_class;
Optr slot_Number_Random_HammersleySequence_currentIndex;
Optr slot_Number_Random_HammersleySequence_samples;
Optr layout_Number_Random_HammersleySequence;


static void init_SMB_next() {
    Symbol SMB_next = new_Symbol(L"next");
    Symbol SMB__plus_ = new_Symbol(L"+");
    SmallInt int_1 = new_SmallInt(1);
    Constant int_1_Const = new_Constant((Optr)int_1);
    // +. 
    Send PSend21719 = new_Send((Optr)slot_Number_Random_HammersleySequence_currentIndex, SMB__plus_, 1, (Optr)int_1_Const);
    Symbol SMB__modulo_ = new_Symbol(L"\\\\");
    // \\. 
    Send PSend21718 = new_Send((Optr)PSend21719, SMB__modulo_, 1, (Optr)slot_Number_Random_PrimeSequence_size);
    // +. 
    Send PSend21717 = new_Send((Optr)PSend21718, SMB__plus_, 1, (Optr)int_1_Const);
    Assign PAssign21716 = new_Assign((Optr)slot_Number_Random_HammersleySequence_currentIndex, (Optr)PSend21717);
    Symbol SMB_at_ = new_Symbol(L"at:");
    // at:. 
    Send PSend21720 = new_Send((Optr)slot_Number_Random_HammersleySequence_samples, SMB_at_, 1, (Optr)slot_Number_Random_HammersleySequence_currentIndex);
    Array PThreadedCode21715 = instantiate_Array_with(ThreadedCode_Class, 0, 23, (Optr)&t_push1, (Optr)PAssign21716, (Optr)&t_push_slot, (Optr)slot_Number_Random_HammersleySequence_currentIndex, (Optr)&t_push_1, (Optr)&t_send1, (Optr)PSend21719, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_size, (Optr)&t_send1, (Optr)PSend21718, (Optr)&t_push_1, (Optr)&t_send1, (Optr)PSend21717, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push_slot, (Optr)slot_Number_Random_HammersleySequence_samples, (Optr)&t_push_slot, (Optr)slot_Number_Random_HammersleySequence_currentIndex, (Optr)&t_send1, (Optr)PSend21720, (Optr)&t_method_return);
    Method PMethod21714 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode21715, 2, PAssign21716, PSend21720);
    
    MethodClosure MC_SMB_next = new_MethodClosure((Method)PMethod21714, Number_Random_HammersleySequence_Class);
    store_method(Number_Random_HammersleySequence_Class, SMB_next, MC_SMB_next);
}


static void init_SMB_refresh() {
    Symbol SMB_refresh = new_Symbol(L"refresh");
    Symbol SMB_new_ = new_Symbol(L"new:");
    // new:. 
    Send PSend21724 = new_Send((Optr)Array_classReference, SMB_new_, 1, (Optr)slot_Number_Random_PrimeSequence_size);
    Assign PAssign21723 = new_Assign((Optr)slot_Number_Random_HammersleySequence_samples, (Optr)PSend21724);
    Variable VAR_i_1_0 = new_Variable_named(L"i", 1);
    Array PArray21726 = new_Array_with(1, (Optr)VAR_i_1_0);
    Symbol SMB__minus_ = new_Symbol(L"-");
    SmallInt int_1 = new_SmallInt(1);
    Constant int_1_Const = new_Constant((Optr)int_1);
    // -. 
    Send PSend21728 = new_Send((Optr)VAR_i_1_0, SMB__minus_, 1, (Optr)int_1_Const);
    Symbol SMB_sampleAt_ = new_Symbol(L"sampleAt:");
    // sampleAt:. 
    Send PSend21729 = new_Send((Optr)self, SMB_sampleAt_, 1, (Optr)PSend21728);
    Symbol SMB_at_put_ = new_Symbol(L"at:put:");
    // at:put:. 
    Send PSend21730 = new_Send((Optr)slot_Number_Random_HammersleySequence_samples, SMB_at_put_, 2, (Optr)VAR_i_1_0, (Optr)PSend21729);
    Array PThreadedCode21727 = instantiate_Array_with(ThreadedCode_Class, 0, 15, (Optr)&t_push_slot, (Optr)slot_Number_Random_HammersleySequence_samples, (Optr)&t_push_variable, (Optr)VAR_i_1_0, (Optr)&t_push_self, (Optr)&t_push_variable, (Optr)VAR_i_1_0, (Optr)&t_push_1, (Optr)&t_send1, (Optr)PSend21728, (Optr)&t_send1, (Optr)PSend21729, (Optr)&t_send2, (Optr)PSend21730, (Optr)&t_method_return);
    Block PBlock21725 = new_Block_with(PArray21726, empty_Array, PThreadedCode21727, 1, PSend21730);
    Symbol SMB_to_do_ = new_Symbol(L"to:do:");
    // to:do:. 
    Send PSend21731 = new_Send((Optr)int_1_Const, SMB_to_do_, 2, (Optr)slot_Number_Random_PrimeSequence_size, (Optr)PBlock21725);
    Symbol SMB__modulo_ = new_Symbol(L"\\\\");
    // \\. 
    Send PSend21733 = new_Send((Optr)slot_Number_Random_HammersleySequence_currentIndex, SMB__modulo_, 1, (Optr)slot_Number_Random_PrimeSequence_size);
    Assign PAssign21732 = new_Assign((Optr)slot_Number_Random_HammersleySequence_currentIndex, (Optr)PSend21733);
    Array PThreadedCode21722 = instantiate_Array_with(ThreadedCode_Class, 0, 30, (Optr)&t_push1, (Optr)PAssign21723, (Optr)&t_push_class_reference, (Optr)Array_classReference, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_size, (Optr)&t_send1, (Optr)PSend21724, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push_1, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_size, (Optr)&t_push_closure, (Optr)PBlock21725, (Optr)&t_send_to_do_, (Optr)&t_continue_to_do_, (Optr)PSend21731, (Optr)&t_zap, (Optr)&t_push1, (Optr)PAssign21732, (Optr)&t_push_slot, (Optr)slot_Number_Random_HammersleySequence_currentIndex, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_size, (Optr)&t_send1, (Optr)PSend21733, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_method_return_self);
    Method PMethod21721 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode21722, 4, PAssign21723, PSend21731, PAssign21732, self);
    
    MethodClosure MC_SMB_refresh = new_MethodClosure((Method)PMethod21721, Number_Random_HammersleySequence_Class);
    store_method(Number_Random_HammersleySequence_Class, SMB_refresh, MC_SMB_refresh);
}


static void init_SMB_initialize() {
    Symbol SMB_initialize = new_Symbol(L"initialize");
    SmallInt int_0 = new_SmallInt(0);
    Constant int_0_Const = new_Constant((Optr)int_0);
    Assign PAssign21736 = new_Assign((Optr)slot_Number_Random_HammersleySequence_currentIndex, (Optr)int_0_Const);
    SmallInt int_100 = new_SmallInt(100);
    Constant int_100_Const = new_Constant((Optr)int_100);
    Assign PAssign21737 = new_Assign((Optr)slot_Number_Random_PrimeSequence_size, (Optr)int_100_Const);
    Super PSuper21738 = new_Super(SMB_initialize, 0);
    Array PThreadedCode21735 = instantiate_Array_with(ThreadedCode_Class, 0, 16, (Optr)&t_push1, (Optr)PAssign21736, (Optr)&t_push_0, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push1, (Optr)PAssign21737, (Optr)&t_push1, (Optr)int_100, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push_self, (Optr)&t_super0, (Optr)PSuper21738, (Optr)&t_zap, (Optr)&t_method_return_self);
    Method PMethod21734 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode21735, 4, PAssign21736, PAssign21737, PSuper21738, self);
    
    MethodClosure MC_SMB_initialize = new_MethodClosure((Method)PMethod21734, Number_Random_HammersleySequence_Class);
    store_method(Number_Random_HammersleySequence_Class, SMB_initialize, MC_SMB_initialize);
}


static void init_SMB_at_() {
    Symbol SMB_at_ = new_Symbol(L"at:");
    Variable VAR_index_0_0 = new_Variable_named(L"index", 0);
    Array PArray21740 = new_Array_with(1, (Optr)VAR_index_0_0);
    Symbol SMB_atWrap_ = new_Symbol(L"atWrap:");
    // atWrap:. 
    Send PSend21742 = new_Send((Optr)slot_Number_Random_HammersleySequence_samples, SMB_atWrap_, 1, (Optr)VAR_index_0_0);
    Array PThreadedCode21741 = instantiate_Array_with(ThreadedCode_Class, 0, 7, (Optr)&t_push_slot, (Optr)slot_Number_Random_HammersleySequence_samples, (Optr)&t_push_variable, (Optr)VAR_index_0_0, (Optr)&t_send1, (Optr)PSend21742, (Optr)&t_method_return);
    Method PMethod21739 = new_Method_with(PArray21740, empty_Array, empty_Array, PThreadedCode21741, 1, PSend21742);
    
    MethodClosure MC_SMB_at_ = new_MethodClosure((Method)PMethod21739, Number_Random_HammersleySequence_Class);
    store_method(Number_Random_HammersleySequence_Class, SMB_at_, MC_SMB_at_);
}


static void init_SMB_sampleAt_() {
    Symbol SMB_sampleAt_ = new_Symbol(L"sampleAt:");
    Variable VAR_index_0_0 = new_Variable_named(L"index", 0);
    Array PArray21744 = new_Array_with(1, (Optr)VAR_index_0_0);
    Variable VAR_output_0_1 = new_Variable_named(L"output", 0);
    Variable VAR_fraction_0_2 = new_Variable_named(L"fraction", 0);
    Variable VAR_copyOfIndex_0_3 = new_Variable_named(L"copyOfIndex", 0);
    Variable VAR_remainder_0_4 = new_Variable_named(L"remainder", 0);
    Array PArray21745 = new_Array_with(4, (Optr)VAR_output_0_1, (Optr)VAR_fraction_0_2, (Optr)VAR_copyOfIndex_0_3, (Optr)VAR_remainder_0_4);
    Float float_0_0 = new_Float(0.0);
    Constant float_0_0_Const = new_Constant((Optr)float_0_0);
    Assign PAssign21747 = new_Assign((Optr)VAR_output_0_1, (Optr)float_0_0_Const);
    Float float_1_0 = new_Float(1.0);
    Constant float_1_0_Const = new_Constant((Optr)float_1_0);
    Symbol SMB__divide_ = new_Symbol(L"/");
    // /. 
    Send PSend21749 = new_Send((Optr)float_1_0_Const, SMB__divide_, 1, (Optr)slot_Number_Random_PrimeSequence_prime);
    Assign PAssign21748 = new_Assign((Optr)VAR_fraction_0_2, (Optr)PSend21749);
    Symbol SMB_asFloat = new_Symbol(L"asFloat");
    // asFloat. 
    Send PSend21751 = new_Send((Optr)VAR_index_0_0, SMB_asFloat, 0);
    Assign PAssign21750 = new_Assign((Optr)VAR_copyOfIndex_0_3, (Optr)PSend21751);
    Symbol SMB__gt_ = new_Symbol(L">");
    SmallInt int_0 = new_SmallInt(0);
    Constant int_0_Const = new_Constant((Optr)int_0);
    // >. 
    Send PSend21754 = new_Send((Optr)VAR_copyOfIndex_0_3, SMB__gt_, 1, (Optr)int_0_Const);
    Array PThreadedCode21753 = instantiate_Array_with(ThreadedCode_Class, 0, 6, (Optr)&t_push_variable, (Optr)VAR_copyOfIndex_0_3, (Optr)&t_push_0, (Optr)&t_send1, (Optr)PSend21754, (Optr)&t_block_return);
    Block PBlock21752 = new_Block_with(empty_Array, empty_Array, PThreadedCode21753, 1, PSend21754);
    Symbol SMB__modulo_ = new_Symbol(L"\\\\");
    // \\. 
    Send PSend21758 = new_Send((Optr)VAR_copyOfIndex_0_3, SMB__modulo_, 1, (Optr)slot_Number_Random_PrimeSequence_prime);
    Assign PAssign21757 = new_Assign((Optr)VAR_remainder_0_4, (Optr)PSend21758);
    Symbol SMB__plus_ = new_Symbol(L"+");
    Symbol SMB__times_ = new_Symbol(L"*");
    // *. 
    Send PSend21761 = new_Send((Optr)VAR_fraction_0_2, SMB__times_, 1, (Optr)VAR_remainder_0_4);
    // +. 
    Send PSend21760 = new_Send((Optr)VAR_output_0_1, SMB__plus_, 1, (Optr)PSend21761);
    Assign PAssign21759 = new_Assign((Optr)VAR_output_0_1, (Optr)PSend21760);
    Symbol SMB__minus_ = new_Symbol(L"-");
    // -. 
    Send PSend21764 = new_Send((Optr)VAR_copyOfIndex_0_3, SMB__minus_, 1, (Optr)VAR_remainder_0_4);
    // /. 
    Send PSend21763 = new_Send((Optr)PSend21764, SMB__divide_, 1, (Optr)slot_Number_Random_PrimeSequence_prime);
    Assign PAssign21762 = new_Assign((Optr)VAR_copyOfIndex_0_3, (Optr)PSend21763);
    // /. 
    Send PSend21766 = new_Send((Optr)VAR_fraction_0_2, SMB__divide_, 1, (Optr)slot_Number_Random_PrimeSequence_prime);
    Assign PAssign21765 = new_Assign((Optr)VAR_fraction_0_2, (Optr)PSend21766);
    Array PThreadedCode21756 = instantiate_Array_with(ThreadedCode_Class, 0, 48, (Optr)&t_push1, (Optr)PAssign21757, (Optr)&t_push_variable, (Optr)VAR_copyOfIndex_0_3, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_prime, (Optr)&t_send1, (Optr)PSend21758, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push1, (Optr)PAssign21759, (Optr)&t_push_variable, (Optr)VAR_output_0_1, (Optr)&t_push_variable, (Optr)VAR_fraction_0_2, (Optr)&t_push_variable, (Optr)VAR_remainder_0_4, (Optr)&t_send1, (Optr)PSend21761, (Optr)&t_send1, (Optr)PSend21760, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push1, (Optr)PAssign21762, (Optr)&t_push_variable, (Optr)VAR_copyOfIndex_0_3, (Optr)&t_push_variable, (Optr)VAR_remainder_0_4, (Optr)&t_send1, (Optr)PSend21764, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_prime, (Optr)&t_send1, (Optr)PSend21763, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push1, (Optr)PAssign21765, (Optr)&t_push_variable, (Optr)VAR_fraction_0_2, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_prime, (Optr)&t_send1, (Optr)PSend21766, (Optr)&t_assign, (Optr)&t_block_return);
    Block PBlock21755 = new_Block_with(empty_Array, empty_Array, PThreadedCode21756, 4, PAssign21757, PAssign21759, PAssign21762, PAssign21765);
    Symbol SMB_whileTrue_ = new_Symbol(L"whileTrue:");
    // whileTrue:. 
    Send PSend21767 = new_Send((Optr)PBlock21752, SMB_whileTrue_, 1, (Optr)PBlock21755);
    Array PThreadedCode21746 = instantiate_Array_with(ThreadedCode_Class, 0, 32, (Optr)&t_push1, (Optr)PAssign21747, (Optr)&t_push_0, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push1, (Optr)PAssign21748, (Optr)&t_push_1, (Optr)&t_push_slot, (Optr)slot_Number_Random_PrimeSequence_prime, (Optr)&t_send1, (Optr)PSend21749, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push1, (Optr)PAssign21750, (Optr)&t_push_variable, (Optr)VAR_index_0_0, (Optr)&t_send0, (Optr)PSend21751, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_push_closure, (Optr)PBlock21752, (Optr)&t_push_closure, (Optr)PBlock21755, (Optr)&t_send1, (Optr)PSend21767, (Optr)&t_zap, (Optr)&t_push_variable, (Optr)VAR_output_0_1, (Optr)&t_method_return);
    Method PMethod21743 = new_Method_with(PArray21744, PArray21745, empty_Array, PThreadedCode21746, 5, PAssign21747, PAssign21748, PAssign21750, PSend21767, VAR_output_0_1);
    
    MethodClosure MC_SMB_sampleAt_ = new_MethodClosure((Method)PMethod21743, Number_Random_HammersleySequence_Class);
    store_method(Number_Random_HammersleySequence_Class, SMB_sampleAt_, MC_SMB_sampleAt_);
}


static void init_class_SMB_randomArray_() {
    Symbol SMB_randomArray_ = new_Symbol(L"randomArray:");
    Variable VAR_size_0_0 = new_Variable_named(L"size", 0);
    Array PArray21769 = new_Array_with(1, (Optr)VAR_size_0_0);
    Symbol SMB_instance = new_Symbol(L"instance");
    // instance. 
    Send PSend21771 = new_Send((Optr)self, SMB_instance, 0);
    Symbol SMB_size_ = new_Symbol(L"size:");
    // size:. 
    Send PSend21772 = new_Send((Optr)PSend21771, SMB_size_, 1, (Optr)VAR_size_0_0);
    Super PSuper21773 = new_Super(SMB_randomArray_, 1, (Optr)VAR_size_0_0);
    Array PThreadedCode21770 = instantiate_Array_with(ThreadedCode_Class, 0, 14, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend21771, (Optr)&t_push_variable, (Optr)VAR_size_0_0, (Optr)&t_send1, (Optr)PSend21772, (Optr)&t_zap, (Optr)&t_push_self, (Optr)&t_push_variable, (Optr)VAR_size_0_0, (Optr)&t_super1, (Optr)PSuper21773, (Optr)&t_method_return);
    Method PMethod21768 = new_Method_with(PArray21769, empty_Array, empty_Array, PThreadedCode21770, 2, PSend21772, PSuper21773);
    
    MethodClosure MC_SMB_randomArray_ = new_MethodClosure((Method)PMethod21768, HEADER(Number_Random_HammersleySequence_Class));
    store_method(HEADER(Number_Random_HammersleySequence_Class), SMB_randomArray_, MC_SMB_randomArray_);
}

void init_Number_Random_HammersleySequence_layout() {
    layout_Number_Random_HammersleySequence_Class_class = (Optr)create_layout_with_vars(ObjectLayout_Class, 7);
    ((Array)layout_Number_Random_HammersleySequence_Class_class)->values[0] = slot_Kernel_Object_Object_Class_class_layout; // layout 
    ((Array)layout_Number_Random_HammersleySequence_Class_class)->values[1] = slot_Kernel_Object_Object_Class_class_superclass; // superclass 
    ((Array)layout_Number_Random_HammersleySequence_Class_class)->values[2] = slot_Kernel_Object_Object_Class_class_methods; // methods 
    ((Array)layout_Number_Random_HammersleySequence_Class_class)->values[3] = slot_Kernel_Object_Object_Class_class_name; // name 
    ((Array)layout_Number_Random_HammersleySequence_Class_class)->values[4] = slot_Kernel_Object_Object_Class_class_package; // package 
    ((Array)layout_Number_Random_HammersleySequence_Class_class)->values[5] = slot_Number_Random_Random_Class_class_instance; // instance 
    ((Array)layout_Number_Random_HammersleySequence_Class_class)->values[6] = slot_Number_Random_PrimeSequence_Class_class_prime; // prime 
    
    Symbol  SMB_HammersleySequence = new_Symbol(L"HammersleySequence");
    slot_Number_Random_HammersleySequence_currentIndex = (Optr)new_Slot(2, L"currentIndex");
    slot_Number_Random_HammersleySequence_samples = (Optr)new_Slot(3, L"samples");
    layout_Number_Random_HammersleySequence = (Optr)create_layout_with_vars(ObjectLayout_Class, 4);
    ((Array)layout_Number_Random_HammersleySequence)->values[0] = slot_Number_Random_PrimeSequence_prime; // prime 
    ((Array)layout_Number_Random_HammersleySequence)->values[1] = slot_Number_Random_PrimeSequence_size; // size 
    ((Array)layout_Number_Random_HammersleySequence)->values[2] = slot_Number_Random_HammersleySequence_currentIndex; // currentIndex 
    ((Array)layout_Number_Random_HammersleySequence)->values[3] = slot_Number_Random_HammersleySequence_samples; // samples 
    Number_Random_HammersleySequence_Class = (Class)new_Class(Number_Random_PrimeSequence_Class, layout_Number_Random_HammersleySequence_Class_class);
    Number_Random_HammersleySequence_Class->layout = layout_Number_Random_HammersleySequence;
    Number_Random_HammersleySequence_Class->name = SMB_HammersleySequence;
    
}

void init_Number_Random_HammersleySequence_methods() {
    init_SMB_next();
    init_SMB_refresh();
    init_SMB_initialize();
    init_SMB_at_();
    init_SMB_sampleAt_();
    init_class_SMB_randomArray_();
    
}