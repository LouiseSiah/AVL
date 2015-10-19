#include "CustomAssertion.h"
#include "Node.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_insertTree_given_9_should_return_expect_tree(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 9);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)13);;};

  if ((((tree->left)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)14);;};

  if ((((tree->right)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)15);;};

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((tree->data)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

}



void test_insertTree_given_9_2_should_return_expect_tree(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 9);

  insertTree(&tree, 2);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)24);;};

  if ((((tree->right)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)25);;};

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((tree->data)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((tree->left->data)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

}



void test_treeBuild_given_9_2_10_should_return_expect_tree(void)

{

  Node *expecTree = ((void *)0);

  Node *tree = treeBuild(3, 9, 2, 10);

  insertTree(&expecTree, 9);

  insertTree(&expecTree, 2);

  insertTree(&expecTree, 10);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)37);;};

  if ((((expecTree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)38);;};



}



void test_treeBuild_given_9_2_10_13_1_6_7_8_should_return_expect_tree(void)

{

  Node *expecTree = ((void *)0);

  Node *tree = treeBuild(8, 9, 2, 10, 13, 1, 6, 7, 8);

  insertTree(&expecTree, 9);

  insertTree(&expecTree, 2);

  insertTree(&expecTree, 10);

  insertTree(&expecTree, 13);

  insertTree(&expecTree, 1);

  insertTree(&expecTree, 6);

  insertTree(&expecTree, 7);

  insertTree(&expecTree, 8);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)54);;};

  if ((((expecTree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)55);;};



}
