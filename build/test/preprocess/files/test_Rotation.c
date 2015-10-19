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

  if ((((tree)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)14);;};

}



void test_leftRotate_given_tree1_should_not_rotate(void)

{

  Node *tree = ((void *)0);

  insertTree(&tree, 20);

  Node *expecTree = ((void *)0);

  insertTree(&expecTree, 20);

  tree = leftRotate(tree);



}



void test_leftRotate_given_tree2_should_rotate_as_expect(void)

{

  Node *tree = treeBuild(2, 20, 40);

  tree = leftRotate(tree);



  Node *expecTree = treeBuild(2, 40, 20);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)33);;};

  if ((((expecTree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)34);;};



}



void test_leftRotate_given_tree3_should_rotate_as_expect(void)

{

  Node *tree = treeBuild(3, 30, 40, 20);

  tree = leftRotate(tree);



  Node *expecTree = treeBuild(3, 40, 30, 20);

  if ((((tree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)44);;};

  if ((((expecTree)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)45);;};



}
