#ifndef PINOCCHIOTEST_H
#define PINOCCHIOTEST_H


#include <pinocchio.h>
#include <signal.h>
#include <setjmp.h>

/* ========================================================================= */

#define NEW_TEST(name) void test_##name() {\
	LOG("\n\033[33m++\033[0m %s() \033[100D\033[60C\033[33m++\033[0m\n", __FUNCTION__);\
    LOG("\033[33m++\033[0m     %s:%u \033[100D\033[60C\033[33m++\033[0m\n", __FILE__, __LINE__);


#define NEW_CLASS_TEST(name) void name() {\
LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"); \
LOG("+++++++ %s %s:%u \n", #name, __FILE__, __LINE__); \
LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

extern jmp_buf Test_Continue;

extern void test_suite_begin(char * suiteName);
extern void test_suite_end(char * suiteName);

extern void run_tests();

#define TEST_SUITE(name, tests) void test_##name() {\
    test_suite_begin(#name);\
    tests\
    test_suite_end(#name);\
}

#define RUN_TEST(f) \
    if (!setjmp(Test_Continue)) { \
        test_##f();\
        printf("\n"); \
    }

#define SKIP_TEST printf("Test skipped: %s %s:%u\n",\
                         __FUNCTION__, __FILE__, __LINE__); \
    return;

/* ========================================================================= */

extern Object Eval_SendConst(Object self, Type_Symbol symbol, Type_Array args);
extern Object Eval_Send(Object self, Type_Symbol symbol, Type_Array args);
extern Object Eval_Send0(Object self, Type_Symbol symbol);
extern Object Eval_Send1(Object self, Type_Symbol symbol, Object arg);

/* ========================================================================= */

#endif // PINOCCHIOTEST_H