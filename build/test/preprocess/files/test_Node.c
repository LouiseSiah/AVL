#include "CustomAssertion.h"
#include "Node.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_insertTree_given_9_should_return_expect_tree(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 9);

  ; customTestAssertTree(0, 9, 0, 0, tree, 13);;

}



void test_insertTree_given_9_2_should_return_expect_tree(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 9);

  insertTree(&tree, 2);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)21);;};

  if ((((tree->right)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)22);;};

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((tree->data)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((tree->left->data)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

}
