#ifndef PINOCCHIOTEST_H
#define PINOCCHIOTEST_H


#include <pinocchio.h>
#include <signal.h>
#include <setjmp.h>

/* ========================================================================= */


/* ========================================================================= */

#define NEW_TEST(name) void test_##name() {\
	LOG("\n\033[33m++\033[0m %s() \033[100D\033[60C\033[33m++\033[0m\n", __FUNCTION__);\
    LOG("\033[33m++\033[0m     %s:%u \033[100D\033[60C\033[33m++\033[0m\n", __FILE__, __LINE__);\
    ASSERT_EMPTY_STACK;

#define NEW_CLASS_TEST(name) void name() {\
LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"); \
LOG("+++++++ %s %s:%u \n", #name, __FILE__, __LINE__); \
LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

extern jmp_buf Test_Continue;

extern void test_suite_begin(char * suiteName);
extern void test_suite_end(char * suiteName, uns_int numtests, uns_int numrun);

extern void run_tests();

#define TEST_SUITE(name, tests) void test_##name() {\
    test_suite_begin(#name);\
    uns_int __ft__ = 0;\
    uns_int __tc__ = 0;\
    tests\
    test_suite_end(#name, __ft__, __tc__);\
}

#define RUN_TEST(f) \
    if (!setjmp(Test_Continue)) { \
        __ft__++;\
        set_env((Object)new_Empty_Runtime_MethodContext());\
        test_##f();\
        printf("\n"); \
        ASSERT_EMPTY_STACK;\
        __tc__++;\
    }

#define SKIP_TEST printf("Test skipped: %s %s:%u\n",\
                         __FUNCTION__, __FILE__, __LINE__); \
    return;
    

#define ASSERT_EMPTY_STACK \
    assert(empty_EXP(), {\
           printf("Stack should be empty but found Object at %li with \n    ", (long int)(_EXP_-Double_Stack));\
           print_Class(peek_EXP(0));\
           }); \
    assert0(empty_CNT());

/* ========================================================================= */

extern Object Eval_Send0(Object self, Type_Symbol symbol);
extern Object Eval_Send1(Object self, Type_Symbol symbol, Object arg);
extern Object Eval_Send2(Object self, Type_Symbol symbol, Object arg,  Object arg2);


/* ========================================================================= */

#endif // PINOCCHIOTEST_H
