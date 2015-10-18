#include "unity.h"
#include "Node.h"
#include "CustomAssertion.h"

Node *node10 = NULL;
Node *node20 = NULL;
Node *node30 = NULL;
Node *node40 = NULL;

void setUp(void){}

void tearDown(void){}

/*
 *          node20(20)
 *         /      \
 * node10(NULL) node30(NULL)
 */
void test_setNode_given_20_node20_as_root_should_return_expected_tree(void)
{
  setNode(0, 20, node10, node30, &node20);
  TEST_ASSERT_EQUAL_TREE(0, 20, node10, node30, node20);
}

/*
 *          node20(20)
 *         /      \
 * node10(10) node30(30)
 */
void test_setNode_given_10_20_30_node20_as_root_should_return_expected_tree(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 30, NULL, NULL, &node30);
  setNode(0, 20, node10, node30, &node20);
  TEST_ASSERT_EQUAL_TREE(0, 20, node10, node30, node20);
}

/*
 *               node30(30)
 *               /      \
 *      node20(20)    node40(40)
 *          /
 *  node10(10)
 */
void test_setNode_given_10_20_30_40_node30_as_root_should_return_expected_tree(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 20, node10, NULL, &node20);
  setNode(0, 40, NULL, NULL, &node40);
  setNode(0, 30, node20, node40, &node30);
  TEST_ASSERT_EQUAL_TREE(0, 30, node20, node40, node30);
  TEST_ASSERT_EQUAL_TREE(0, 20, node10, NULL, node20);
  TEST_ASSERT_EQUAL_TREE(0, 10, NULL, NULL, node10);
  TEST_ASSERT_EQUAL_TREE(0, 40, NULL, NULL, node40);
}