void test_method_evaluation()
{
    Type_Array * body       = new_Raw_Array(0);
    AST_Method * method     = new_Method(1, body);
    Object method_const     = (Object)new_Constant((Object)method);
    Type_SmallInt * integer = new_SmallInt(120);
    Object integer_const    = (Object)new_Constant((Object)integer);
    Type_SmallInt * integer7 = new_SmallInt(7);
    Object integer7_const    = (Object)new_Constant((Object)integer7);
    
    Object result = Eval((Object)new_Send(method_const, Symbol_eval, new_Raw_Array(0)));
    assert(result == (Object)method);
    
    // with one body element ---------------------------------------------------
    method->body = new_Array_With(1, integer_const);
    result       = Eval((Object)new_Send(method_const, Symbol_eval, new_Raw_Array(0)));
    //printf("%ls\n", Object_classname(result));
    assert(result == (Object)integer);
    
    // with one argument -------------------------------------------------------
    AST_Variable * var      = new_Variable(L"myVar");
    method->body            = new_Array_With(3, integer7_const);
    method->body->values[2] = (Object)var;
    
    var->key = (Object)method;
    var->index = 0;
    
    result       = Eval((Object)new_Send(method_const, Symbol_eval_, 
                                         new_Array_With(1, (Object)integer_const)));
    //printf("%ls\n", Object_classname(result));
    assert(result == (Object)integer);
}


void test_method_invocation_with_arguments()
{
    AST_Variable * var  = new_Variable(L"myVar");
    Type_Array * body   = new_Array_With(1, (Object)var);
    AST_Method * method = new_Method(0, body);
    var->key = (Object)method;
    var->index = 0;
    
    Type_Symbol * test           = new_Symbol(L"test");
    Type_SmallInt * integer      = new_SmallInt(120);
    AST_Constant * integer_const = new_Constant((Object)integer);
    store_method(SmallInt_Class, (Object)test, (Object)method);
    Type_Array * args = new_Array_With(1, (Object)integer_const);
    Object result     = Eval((Object)new_Send((Object)integer_const, (Object)test, args));
    assert(result == (Object)integer);
    
}


void test_method_invocation()
{
    Type_Array * body = new_Raw_Array(0);
    AST_Method * method = new_Method(0, body);
    Type_Symbol * test = new_Symbol(L"test");
    Type_SmallInt * integer = new_SmallInt(120);
    AST_Constant * integer_const = new_Constant((Object)integer);
    store_method(SmallInt_Class, (Object)test, (Object)method);
    Object result = Eval((Object)new_Send((Object)integer_const, (Object)test, new_Raw_Array(0)));
    assert(result == (Object)integer);
    
    // with 1 body element
    Type_SmallInt * integer5 = new_SmallInt(5);
    AST_Constant * integer5_const = new_Constant((Object)integer5);
    body = new_Array_With(1, (Object)integer5_const);
    method = new_Method(0, body);
    store_method(SmallInt_Class, (Object)test, (Object)method);
    result = Eval((Object)new_Send((Object)integer_const, (Object)test, new_Raw_Array(0)));
    assert(result == (Object)integer5);
    
    // with 2 body element
    Type_SmallInt * integer6 = new_SmallInt(6);
    AST_Constant * integer6_const = new_Constant((Object)integer6);
    body = new_Array_With(2, (Object)integer5_const);
    body->values[1] = (Object)integer6_const;
    method = new_Method(0, body);
    store_method(SmallInt_Class, (Object)test, (Object)method);
    result = Eval((Object)new_Send((Object)integer_const, (Object)test, new_Raw_Array(0)));
    assert(result == (Object)integer6);
    
    // with 3 body element
    Type_SmallInt * integer7 = new_SmallInt(7);
    AST_Constant * integer7_const = new_Constant((Object)integer7);
    body = new_Array_With(3, (Object)integer5_const);
    body->values[1] = (Object)integer6_const;
    body->values[2] = (Object)integer7_const;
    method = new_Method(0, body);
    store_method(SmallInt_Class, (Object)test, (Object)method);
    result = Eval((Object)new_Send((Object)integer_const, (Object)test, new_Raw_Array(0)));
    assert(result == (Object)integer7);
}

/* ======================================================================== */

void test_Method()
{
    test_method_invocation_with_arguments();
    test_method_invocation();
    test_method_evaluation();
}