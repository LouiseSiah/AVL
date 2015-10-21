#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include "CustomAssertion.h"

Node node10, node20, node30, node40, node50, node60, node70, node80, node90, node100;
// Node *node10 = NULL;
// Node *node20 = NULL;
// Node *node30 = NULL;
// Node *node40 = NULL;
// Node *node50 = NULL;
// Node *node60 = NULL;
// Node *node70 = NULL;
// Node *node80 = NULL;
// Node *node90 = NULL;
// Node *node100 = NULL;
// Node *node110 = NULL;
// Node *node120 = NULL;
// Node *node130 = NULL;
// void resetNode(Node *node, int value)
// {
  // node->data = value;
  // node->balanceFactor = 0;
  // node->left = NULL;
  // node->right = NULL;
// }

void setUp(void)
{
  // resetNode(&node10, 10);
  // resetNode(&node20F, 20);
  // resetNode(&node30, 30);
  // resetNode(&node40, 40);
  // resetNode(&node50, 50);
  // resetNode(&node60, 60);
}

void tearDown(void) {}

/**
 *         50(0)        20         50(-1)
 *                ------>         /
 *                              20(0)
 */
void test_avlAdd_add_node20_should_F(void)
{
  int change;
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 20, NULL, NULL, &node20);
  Node *root;
  root = &node50;
  change = avlAdd(&root, &node20);
  TEST_ASSERT_EQUAL(1, change);
  TEST_ASSERT_EQUAL_TREE(-1, 50, &node20, NULL, root);
  TEST_ASSERT_EQUAL_TREE(0, 20, NULL, NULL, root->left);
}

/**
 *         50(0)        60         50(+1)
 *                ------>           \
 *                                  60(0)
 */
void test_avlAddadd_node60_should_F()
{
  int change;
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 60, NULL, NULL, &node60);
  Node *root;
  root = &node50;
  change = avlAdd(&root, &node60);
  TEST_ASSERT_EQUAL(1, change);
  TEST_ASSERT_EQUAL_TREE(1, 50, NULL, &node60, root);
  TEST_ASSERT_EQUAL_TREE(0, 60, NULL, NULL, root->right);
}

/**
 *     50(1)       20          50(0)
 *        \       ------>      / \
 *      60(0)              20(0) 60(0)
 */
void test_avlAddadd_node60_given_node20_should_F()
{
  int change;
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 60, NULL, NULL, &node60);
  setNode(1, 50, NULL, &node60, &node50);
  Node *root;
  root = &node50;
  change = avlAdd(&root, &node20);
  TEST_ASSERT_EQUAL(0, change);
  TEST_ASSERT_EQUAL_TREE(0, 50, &node20, &node60, root);
  // TEST_ASSERT_EQUAL_TREE(0, 60, NULL, NULL, root->right);
}

/**
 *      50(0)       10            50(-1)
 *      /  \      ----->           / \ 
 *   20(0) 60(0)               20(-1) 60(0) 
 *                               /
 *                             10(0)
 */
void test_avlAddadd_node60_node20_given_node10_should_F()
{
  int change;
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 60, NULL, NULL, &node60);
  setNode(0, 50, NULL, &node60, &node50);
  Node *root;
  root = &node50;
  change = avlAdd(&root, &node10);
  TEST_ASSERT_EQUAL(1, change);
  TEST_ASSERT_EQUAL_TREE(-1, 50, &node20, &node60, root);
  // TEST_ASSERT_EQUAL_TREE(0, 60, NULL, NULL, root->right);
}
