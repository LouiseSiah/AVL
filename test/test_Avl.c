#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include "CustomAssertion.h"
#include "CException.h"
#include "ErrorObject.h"

Node node0, node10, node20, node30, node40, node50, node60, node70, node80, node90, node100;

void setUp(void){}

void tearDown(void){}

void test_avlAdd_given_NULL_newNode_should_catch_the_error(void)
{
  setNode(0, 0, NULL, NULL, &node0);
  int change;
  Node *root = &node50;
  Node *null = NULL;

  
  ErrorObject *err;
  Try
  {
    change = avlAdd(&root, null);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The new Node is NULL, cannot add to the tree.", err->errorMsg);
    TEST_ASSERT_EQUAL(NEWNODE_IS_NULL, err->errorCode);

    freeError(err);
  }
}

void test_avlAdd_given_NULL_root_should_catch_the_error(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  int change;
  Node *root = NULL;
  
  ErrorObject *err;
  Try
  {
    change = avlAdd(&root, &node10);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The root is NULL, cannot add newNode to empty tree.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_EMPTY, err->errorCode);

    freeError(err);
  }
}

/**
 *         50(0)        20         50(-1)
 *                ------>         /
 *                              20(0)
 */
void test_avlAdd_add_node20_should_able_correct_root_balanceFactor_to_minus1_and_return_1(void)
{
  int change;
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 20, NULL, NULL, &node20);
  Node *root = &node50;
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
void test_avlAdd_add_node60_should_able_correct_root_balanceFactor_to_plus1_and_return_1(void)
{
  int change;
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 60, NULL, NULL, &node60);
  Node *root = &node50;
  change = avlAdd(&root, &node60);
  TEST_ASSERT_EQUAL(1, change);
  TEST_ASSERT_EQUAL_TREE(1, 50, NULL, &node60, root);
  TEST_ASSERT_EQUAL_TREE(0, 60, NULL, NULL, root->right);
}

/**
 *     50(0)       20 ,60       50(0)
 *                 ------>      / \
 *                         20(0) 60(0)
 */
void test_avlAdd_add_node20_and_node60_should_able_correct_root_balanceFactor_to_0_and_return_0(void)
{
  int change;
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 60, NULL, NULL, &node60);
  setNode(0, 50, NULL, NULL, &node50);
  Node *root = &node50;

  change = avlAdd(&root, &node20);
  TEST_ASSERT_EQUAL(1, change);
  change = avlAdd(&root, &node60);
  TEST_ASSERT_EQUAL(0, change);
  TEST_ASSERT_EQUAL_TREE(0, 50, &node20, &node60, root);
  TEST_ASSERT_EQUAL_TREE(0, 20, NULL, NULL, root->left);
  TEST_ASSERT_EQUAL_TREE(0, 60, NULL, NULL, root->right);
}

/**
 *          50(0)       90           50(+1)
 *         /    \     ----->           / \ 
 *      20(-1) 70(0)               20(-1) 70(+1) 
 *      /     /   \                /     /  \
 *   10(0) 60(0) 90(0)         10(0) 60(0) 90(-1)
 *                                          /
 *                                        80(0)
 */
void test_avlAdd_add_node90_to_multi_level_tree_should_able_correct_root_balanceFactor_to_plus1_and_return_plus1(void)
{
  int change;
  setNode(0, 10, NULL, NULL, &node10);
  setNode(-1, 20, &node10, NULL, &node20);
  setNode(0, 60, NULL, NULL, &node60);
  setNode(0, 90, NULL, NULL, &node90);
  setNode(0, 70, &node60, &node90, &node70);
  setNode(0, 50, &node20, &node70, &node50);
  setNode(0, 80, NULL, NULL, &node80);
  
  Node *root = &node50;
  
  change = avlAdd(&root, &node80);
  
  TEST_ASSERT_EQUAL(1, change);
  TEST_ASSERT_EQUAL_TREE(1, 50, &node20, &node70, root);
  TEST_ASSERT_EQUAL_TREE(-1, 20, &node10, NULL, root->left);
  TEST_ASSERT_EQUAL_TREE(1, 70, &node60, &node90, root->right);
  TEST_ASSERT_EQUAL_TREE(0, 10, NULL, NULL, root->left->left);
  TEST_ASSERT_EQUAL_TREE(0, 60, NULL, NULL, root->right->left);
  TEST_ASSERT_EQUAL_TREE(-1, 90, &node80,  NULL, root->right->right);
  TEST_ASSERT_EQUAL_TREE(0, 80, NULL, NULL, root->right->right->left);
}
