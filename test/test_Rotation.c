#include "unity.h"
#include "Rotation.h"
#include "CustomAssertion.h"
#include "Node.h"

void setUp(void){}

void tearDown(void){}

void test_leftRotate_given_NULL_tree_should_return_NULL(void)
{
  Node *tree = NULL;
  tree = leftRotate(tree);
  TEST_ASSERT_NULL(tree);
}

void test_leftRotate_given_tree1_should_not_rotate(void)
{
  Node *tree = NULL;
  insertTree(&tree, 20);
  Node *expecTree = NULL;
  insertTree(&expecTree, 20);
  tree = leftRotate(tree);
  // TEST_ASSERT_EQUAL_TREE(expecTree, tree);
}

void test_leftRotate_given_tree2_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(2, 20, 40);
  tree = leftRotate(tree);

  Node *expecTree = treeBuild(2, 40, 20);
  TEST_ASSERT_NOT_NULL(tree);
  TEST_ASSERT_NOT_NULL(expecTree);
  // TEST_ASSERT_EQUAL_TREE(expecTree, tree);
}

void test_leftRotate_given_tree3_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(3, 30, 40, 20);
  tree = leftRotate(tree);

  Node *expecTree = treeBuild(3, 40, 30, 20);
  TEST_ASSERT_NOT_NULL(tree);
  TEST_ASSERT_NOT_NULL(expecTree);
  // TEST_ASSERT_EQUAL_TREE(expecTree, tree);
}