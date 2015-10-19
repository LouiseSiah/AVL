/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_leftRotate_given_NULL_tree_should_return_NULL(void);
extern void test_leftRotate_given_tree1_should_not_rotate(void);
extern void test_leftRotate_given_tree2_should_rotate_as_expect(void);
extern void test_leftRotate_given_tree3_should_rotate_as_expect(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("test_Rotation.c");
  RUN_TEST(test_leftRotate_given_NULL_tree_should_return_NULL, 10);
  RUN_TEST(test_leftRotate_given_tree1_should_not_rotate, 17);
  RUN_TEST(test_leftRotate_given_tree2_should_rotate_as_expect, 27);
  RUN_TEST(test_leftRotate_given_tree3_should_rotate_as_expect, 38);

  return (UnityEnd());
}
