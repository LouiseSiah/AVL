#include "unity.h"
#include "Node.h"
#include "CustomAssertion.h"


void setUp(void){}

void tearDown(void){}

void test_insertTree_insert_9_should_give_one_node_tree_only(void)
{
  Node *tree = NULL;
  insertTree(&tree, 9);
  TEST_ASSERT_NOT_NULL(tree);
  TEST_ASSERT_NULL(tree->left);
  TEST_ASSERT_NULL(tree->right);
  TEST_ASSERT_EQUAL(9, tree->data);
}

void test_insertTree_insert_9_2_should_give_expected_tree(void)
{
  Node *tree = NULL;
  insertTree(&tree, 9);
  insertTree(&tree, 2);
  TEST_ASSERT_NOT_NULL(tree);
  TEST_ASSERT_NULL(tree->right);
  TEST_ASSERT_EQUAL(9, tree->data);
  TEST_ASSERT_EQUAL(2, tree->left->data);
}

void test_treeBuild_insert_9_2_10_should_return_expect_tree(void)
{
  Node *tree = treeBuild(3, 9, 2, 10);
  TEST_ASSERT_NOT_NULL(tree);
  // TEST_ASSERT_NOT_NULL(tree->left);
  // TEST_ASSERT_NOT_NULL(tree->right);
  TEST_ASSERT_EQUAL(9, tree->data);
  TEST_ASSERT_EQUAL(2, tree->left->data);
  TEST_ASSERT_EQUAL(10, tree->right->data);
  // TEST_ASSERT_EQUAL_TREE(tree, tree); 
}