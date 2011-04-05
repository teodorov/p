#include <tests/pinocchio_test.h>

void test_symbol_table_can_grow(void **state) {
	Symbol s = new_Symbol(L"test");
        for( int i= 0; i < 2000; i++)
        {
		//convert i to a string that can be used as key
                wchar_t str[] = { (int)'0'+(i/1000), (int)'0'+(i/100%100), (int)'0'+(i/10%10), (int)'0'+(i%10), 0 };
		new_Symbol(str);
	}
	assert_int_equal( s, new_Symbol(L"test") );
	assert_int_not_equal( s, new_Symbol(L"test2") );
	assert_int_not_equal( s, new_Symbol(L"0000") );
}
