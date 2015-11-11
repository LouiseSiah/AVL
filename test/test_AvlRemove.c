#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include "CustomAssertion.h"
#include "CException.h"
#include "ErrorObject.h"
#include "Rotation.h"

Node node0, node10, node20, node30, node40, node50, node60, node70, node80, node90, node100;

void setUp(void){}

void tearDown(void){}

void test_avlRemove_given_NULL_tree_to_remove_should_catch_the_error(void)
{
  setNode(0, 0, NULL, NULL, &node0);
  int heightChange;
  Node *root = NULL;

  ErrorObject *err;
  Try
  {
    root = avlRemove(&root, 60, &heightChange);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The root is NULL, cannot remove any node from empty tree.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_EMPTY, err->errorCode);

    freeError(err);
  }
}

/**
 *      50(0)       - 60       50(-1) 
 *     /   \      ------>      /
 *  20(0) 60(0)              20(0)
 */
void test_avlRemove_60_from_tree1_should_give_heightChange_as_1(void)
{
  int heightChange = -1;
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 60, NULL, NULL, &node60);
  setNode(0, 50, &node20, &node60, &node50);
  Node *root = &node50;
  
  Node *remove;
  remove = avlRemove(&root, 60, &heightChange);
  TEST_ASSERT_EQUAL_PTR(remove, &node60);
  TEST_ASSERT_EQUAL(0, heightChange);
  TEST_ASSERT_EQUAL_TREE(-1, 50, &node20, NULL, root);
}
 
/**
 *      50(0)       - 20       50(+1) 
 *     /   \      ------>        \
 *  20(0) 60(0)                 60(0)
 */
void test_avlRemove_20_from_tree1_should_give_heightChange_as_1(void)
{
  int heightChange;
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 60, NULL, NULL, &node60);
  setNode(0, 50, &node20, &node60, &node50);
  Node *root = &node50;
  
  Node *remove = avlRemove(&root, 20, &heightChange);
  TEST_ASSERT_EQUAL_PTR(remove, &node20);
  TEST_ASSERT_EQUAL(0, heightChange);
  TEST_ASSERT_EQUAL_TREE(1, 50, NULL, &node60, root);
}

/**
 *     50(+1)                     50(+1)   
 *     / \          - 60          / \      
 *  20(0) 70(0)    ------>   20(0) 70(+1)  
 *        / \                          \     
 *    60(0)  80(0)                     80(0) 
 */
void test_avlRemove_60_from_tree2_should_give_heightChange_as_0(void)
{
  int heightChange;
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 80, NULL, NULL, &node80);
  setNode(0, 60, NULL, NULL, &node60);
  setNode(0, 70, &node60, &node80, &node70);
  setNode(1, 50, &node20, &node70, &node50);
  Node *root = &node50;
  
  Node *remove = avlRemove(&root, 60, &heightChange);
  
  TEST_ASSERT_EQUAL(0, heightChange);
  TEST_ASSERT_EQUAL_PTR(remove, &node60);
  TEST_ASSERT_EQUAL_TREE(1, 50, &node20, &node70, root);
  TEST_ASSERT_EQUAL_TREE(0, 20, NULL, NULL, root->left);
  TEST_ASSERT_EQUAL_TREE(1, 70, NULL, &node80, root->right);
  TEST_ASSERT_EQUAL_TREE(0, 80, NULL, NULL, root->right->right);
}

/**
 *           50(-1)                    50(-1)  
 *           / \                        / \      
 *        20(0) 70(0)   - 30      20(-1) 70(0) 
 *        / \          ----->        /           
 *    10(0) 30(0)                10(0)           
 */
void test_avlRemove_30_from_tree3_should_give_heightChange_as_0(void)
{
  int heightChange;
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 30, NULL, NULL, &node30);
  setNode(0, 20, &node10, &node30, &node20);
  setNode(0, 70, NULL, NULL, &node70);
  setNode(-1, 50, &node20, &node70, &node50);
  Node *root = &node50;
  
  Node *remove = avlRemove(&root, 30, &heightChange);
  
  TEST_ASSERT_EQUAL(0, heightChange);
  TEST_ASSERT_EQUAL_PTR(remove, &node30);
  TEST_ASSERT_EQUAL_TREE(-1, 50, &node20, &node70, root);
  TEST_ASSERT_EQUAL_TREE(-1, 20, &node10, NULL, root->left);
  TEST_ASSERT_EQUAL_TREE(0, 70, NULL, NULL, root->right);
  TEST_ASSERT_EQUAL_TREE(0, 10, NULL, NULL, root->left->left);
}

/**      Before remove            After remove                          After remove and rotation
 *          50(+1)                    50(+2) <--VIOLATION, leftRotate        80(0)
 *         /   \          - 30       /   \                                  /    \
 *     40(-1) 80(+1)    ----->    40(0) 80(+1)                          50(0)  90(+1)
 *      /      /   \                     /  \                            /  \      \
 *    30(0) 70(0) 90(+1)              70(0) 90(+1)                    40(0) 70(0) 100(0)
 *                  \                         \     
 *                 100(0)                   100(0)    
 */
void test_avlRemove_30_from_tree4_give_plus2_plus1_violation_then_leftRotate_should_give_heightChange_as_0(void)
{
  int heightChange;
  setNode(0, 30, NULL, NULL, &node30);
  setNode(-1, 40, &node30, NULL, &node40);
  setNode(0, 70, NULL, NULL, &node70);
  setNode(0, 100, NULL, NULL, &node100);
  setNode(0, 90, NULL, &node100, &node90);
  setNode(1, 80, &node70, &node90, &node80);
  setNode(1, 50, &node40, &node80, &node50);
  Node *root = &node50;
  
  Node *remove = avlRemove(&root, 30, &heightChange);
  
  TEST_ASSERT_EQUAL(1, heightChange);
  TEST_ASSERT_EQUAL_PTR(remove, &node30);
  TEST_ASSERT_EQUAL_TREE(0, 80, &node50, &node90, root);
  TEST_ASSERT_EQUAL_TREE(0, 50, &node40, &node70, root->left);
  TEST_ASSERT_EQUAL_TREE(0, 40, NULL, NULL, root->left->left);
  TEST_ASSERT_EQUAL_TREE(0, 70, NULL, NULL, root->left->right);
  TEST_ASSERT_EQUAL_TREE(0, 90, NULL, &node100, root->right);
  TEST_ASSERT_EQUAL_TREE(0, 100, NULL, NULL, root->right->right);
}

/**      Before remove            After remove                          After remove and rotation
 *          50(+1)                    50(+2) <--VIOLATION, leftRotate        80(-1)
 *         /    \          - 30       /   \                                  /    \
 *     40(-1)  80(0)     ------>   40(0) 80(0)                          50(0)   90(+1)
 *      /     /    \                     /   \                            /  \      \
 *   30(0)  70(-1) 90(+1)             70(-1) 90(+1)                    40(0) 70(-1) 100(0)
 *          /       \                  /       \                             /  
 *       60(0)      100(0)          60(0)     100(0)                       60(0)  
 */