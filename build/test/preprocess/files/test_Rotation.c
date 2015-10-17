#include "Node.h"
#include "CustomAssertion.h"
#include "Rotation.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}





void test_leftRotate_given_NULL_tree_should_return_NULL(void)

{

  Node *tree = ((void *)0);

  tree = leftRotate(tree);

  if ((((tree)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)15);;};

}













void test_leftRotate_given_tree1_should_not_rotate(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 30);

  tree = leftRotate(tree);

  ; customTestAssertTree(0, 30, 0, 0, tree, 28);;

}













void test_leftRotate_given_tree2_should_rotate_as_expect(void)

{

  Node *tree = treeBuild(2, 30, 40);

  tree = leftRotate(tree);



  ; customTestAssertTree(0, 40, 30, 0, tree, 41);;

  ; customTestAssertTree(0, 30, 0, 0, tree->left, 42);;

}

void test_leftRotate_given_tree3_should_rotate_as_expect(void)

{

  Node *tree = treeBuild(3, 30, 40, 20);

  tree = leftRotate(tree);



  ; customTestAssertTree(0, 40, 30, 0, tree, 57);;

  ; customTestAssertTree(0, 30, 20, 0, tree->left, 58);;

  ; customTestAssertTree(0, 20, 0, 0, tree->left->left, 59);;

}

void test_leftRotate_given_tree4_should_rotate_as_expect(void)

{

  Node *tree = treeBuild(11, 30, 20, 10, 25, 40, 50, 35, 33, 38, 45, 60);

  tree = leftRotate(tree);



  ; customTestAssertTree(0, 40, 30, 50, tree, 77);;

  ; customTestAssertTree(0, 30, 20, 35, tree->left, 78);;

  ; customTestAssertTree(0, 20, 10, 25, tree->left->left, 79);;

  ; customTestAssertTree(0, 10, 0, 0, tree->left->left->left, 80);;

  ; customTestAssertTree(0, 25, 0, 0, tree->left->left->right, 81);;

  ; customTestAssertTree(0, 35, 33, 38, tree->left->right, 82);;

  ; customTestAssertTree(0, 33, 0, 0, tree->left->right->left, 83);;

  ; customTestAssertTree(0, 38, 0, 0, tree->left->right->right, 84);;

  ; customTestAssertTree(0, 50, 45, 60, tree->right, 85);;

  ; customTestAssertTree(0, 45, 0, 0, tree->right->left, 86);;

  ; customTestAssertTree(0, 60, 0, 0, tree->right->right, 87);;

}
