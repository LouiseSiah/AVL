#include "unity.h"
#include "Node.h"
#include "CustomAssertion.h"

void setUp(void){}

void tearDown(void){}

Node *node10 = NULL;
Node *node20 = NULL;
Node *node30 = NULL;

// Node *node10 = (Node *)malloc(sizeof(Node));
// node20 = (Node *)malloc(sizeof(Node));
// node30 = (Node *)malloc(sizeof(Node));

void test_setNode_given_20_should_return_expected_tree(void)
{
  setNode(0, 20, node10, node30, &node20);
  TEST_ASSERT_EQUAL_TREE(0, 20, 0, 0, node20);
}

/*
void test_insertTree_given_9_should_return_expect_tree(void)
{
  Node *tree = NULL;
  insertTree(&tree, 9);
  TEST_ASSERT_EQUAL_TREE(0, 9, 0, 0, tree);
}

void test_insertTree_given_9_2_should_return_expect_tree(void)
{
  Node *tree = NULL;
  insertTree(&tree, 9);
  insertTree(&tree, 2);
  TEST_ASSERT_NOT_NULL(tree);
  TEST_ASSERT_NULL(tree->right);
  TEST_ASSERT_EQUAL(9, tree->data);
  TEST_ASSERT_EQUAL(2, tree->left->data);
}

void test_treeBuild_given_9_2_10_should_return_expect_tree(void)
{
  Node *expecTree = NULL;
  Node *tree = treeBuild(3, 9, 2, 10);
  insertTree(&expecTree, 9);
  insertTree(&expecTree, 2);
  insertTree(&expecTree, 10);
  TEST_ASSERT_NOT_NULL(tree);
  TEST_ASSERT_NOT_NULL(expecTree);
  TEST_ASSERT_EQUAL_TREE(expecTree, tree);
}

void test_treeBuild_given_9_2_10_13_1_6_7_8_should_return_expect_tree(void)
{
  Node *expecTree = NULL;
  Node *tree = treeBuild(8, 9, 2, 10, 13, 1, 6, 7, 8);
  insertTree(&expecTree, 9);
  insertTree(&expecTree, 2);
  insertTree(&expecTree, 10);
  insertTree(&expecTree, 13);
  insertTree(&expecTree, 1);
  insertTree(&expecTree, 6);
  insertTree(&expecTree, 7);
  insertTree(&expecTree, 8);
  TEST_ASSERT_NOT_NULL(tree);
  TEST_ASSERT_NOT_NULL(expecTree);
  // TEST_ASSERT_EQUAL_TREE(expecTree, tree);
}
*/