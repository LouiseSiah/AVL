#include "CustomAssertion.h"
#include "Node.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}



void test_insertTree_insert_9_should_give_one_node_tree_only(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 9);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)14);;};

  if ((((tree->left)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)15);;};

  if ((((tree->right)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)16);;};

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((tree->data)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

}



void test_insertTree_insert_9_2_should_give_expected_tree(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 9);

  insertTree(&tree, 2);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)25);;};

  if ((((tree->right)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)26);;};

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((tree->data)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((tree->left->data)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

}



void test_treeBuild_insert_9_2_10_should_return_expect_tree(void)

{

  Node *tree = treeBuild(3, 9, 2, 10);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)34);;};





  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((tree->data)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((tree->left->data)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((tree->right->data)), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);



}
