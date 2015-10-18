#include "unity.h"
#include "Rotation.h"
#include "CustomAssertion.h"
#include "Node.h"
#include "ErrorObject.h"
#include "CException.h"
Node *node10 = NULL;
Node *node20 = NULL;
Node *node30 = NULL;
Node *node40 = NULL;
Node *node50 = NULL;
Node *node60 = NULL;
Node *node70 = NULL;

void setUp(void){}

void tearDown(void){}

// throw error?
void test_leftRotate_given_NULL_tree_should_catch_the_error(void)
{
  node30 = NULL;
  ErrorObject *err;
  Try
  {
    Node *tree = leftRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_NULL, err->errorCode);

    freeError(err);
  }
}

/*          Before               After
 *        node30(30)            node30(30)
 *         /  \                  /  \
 *     node20 NULL         node20 NULL
 */
void test_leftRotate_given_tree1_should_catch_the_error(void)
{
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 30, node20, NULL, &node30);
  ErrorObject *err;
  Try
  {
    Node *tree = leftRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! There is no Child to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(NO_CHILD_TO_ROTATE, err->errorCode);

    freeError(err);
  }
}

/*          Before                             After
 *           20                                  40
 *         /   \                               /   \
 *       10     40                           20     50
 *             / \                         /  \
 *            30  50                     10   30
 */
void test_leftRotate_given_tree2_should_rotate_as_expect(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 30, NULL, NULL, &node30);
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 40, node30, node50, &node40);
  setNode(0, 20, node10, node40, &node20);

  Node *tree = leftRotate(node20);

  TEST_ASSERT_EQUAL_TREE(0, 40, node20, node50, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, node10, node30, tree->left);
}

void test_rightRotate_given_NULL_tree_should_catch_the_error(void)
{
  node30 = NULL;
  ErrorObject *err;
  Try
  {
    Node *tree = rightRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_NULL, err->errorCode);

    freeError(err);
  }
}

/*          Before               After
 *        node30(30)            node30(30)
 *         /  \                  /  \
 *      NULL  node20        NULL  node20
 */
void test_rightRotate_given_tree1_should_catch_the_error(void)
{
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 30, NULL, node20, &node30);
  ErrorObject *err;
  Try
  {
    Node *tree = rightRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! There is no Child to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(NO_CHILD_TO_ROTATE, err->errorCode);

    freeError(err);
  }
}

/*          Before                             After
 *           40                                  20
 *         /   \                               /    \
 *       20    50                            10     40
 *      / \                                        /   \
 *    10  30                                      30   50
 */
void test_rightRotate_given_tree2R_should_rotate_as_expect(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 30, NULL, NULL, &node30);
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 20, node10, node30, &node20);
  setNode(0, 40, node20, node50, &node40);

  Node *tree = rightRotate(node40);

  TEST_ASSERT_EQUAL_TREE(0, 20, node10, node40, tree);
  TEST_ASSERT_EQUAL_TREE(0, 40, node30, node50, tree->right);
}

void test_leftRightRotate_given_NULL_tree_should_catch_the_error(void)
{
  node30 = NULL;
  ErrorObject *err;
  Try
  {
    Node *tree = leftRightRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_NULL, err->errorCode);
    
    freeError(err);
  }
}

/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *     NULL NULL             NULL   NULL  
 */
void test_leftRightRotate_given_tree1A_should_catch_the_error(void)
{
  setNode(0, 30, NULL, NULL, &node30);
  
  ErrorObject *err;
  Try
  {
    Node *tree = leftRightRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! There is no Child to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(NO_CHILD_TO_ROTATE, err->errorCode);

    freeError(err);
  }
}

/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *     node20 NULL        node20    NULL  
 */
void test_leftRightRotate_given_tree1_should_catch_the_error(void)
{
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 30, node20, NULL, &node30);
  
  ErrorObject *err;
  Try
  {
    Node *tree = leftRightRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! There is no Child to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(NO_CHILD_TO_ROTATE, err->errorCode);

    freeError(err);
  }
}

/*          Before                             After
 *           60                                  40
 *         /   \                                /  \
 *       20     70                           20     60
 *      / \                                /  \    / \
 *    10  40                             10    30 50  70
 *       / \
 *     30  50
 */
void test_leftRightRotate_given_tree2LR_should_rotate_as_expect(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 30, NULL, NULL, &node30);
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 70, NULL, NULL, &node70);
  setNode(0, 40, node30, node50, &node40);
  setNode(0, 20, node10, node40, &node20);
  setNode(0, 60, node20, node70, &node60);
  
  Node *tree = leftRightRotate(node60);
  
  TEST_ASSERT_EQUAL_TREE(0, 40, node20, node60, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, node10, node30, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 60, node50, node70, tree->right);
}

void test_rightLeftRotate_given_NULL_tree_should_catch_the_error(void)
{
  node30 = NULL;
  ErrorObject *err;
  Try
  {
    Node *tree = rightLeftRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_NULL, err->errorCode);
    
    freeError(err);
  }
}

/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *      NULL  NULL            NULL  NULL
 */
void test_rightLeftRotate_given_tree1A_should_not_rotate(void)
{
  setNode(0, 30, NULL, NULL, &node30);
  ErrorObject *err;
  Try
  {
    Node *tree = rightLeftRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! There is no Child to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(NO_CHILD_TO_ROTATE, err->errorCode);

    freeError(err);
  }
}


/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *      NULL  node20        NULL  node20
 */
void test_rightLeftRotate_given_tree1_should_not_rotate(void)
{
  setNode(0, 20, NULL, NULL, &node20);
  setNode(0, 30, NULL, node20, &node30);
  ErrorObject *err;
  Try
  {
    Node *tree = rightLeftRotate(node30);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey! There is no Child to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(NO_CHILD_TO_ROTATE, err->errorCode);

    freeError(err);
  }
}

/*          Before                             After
 *           20                                  40
 *         /   \                                /  \
 *       10     60                           20     60
 *              / \                         /  \    / \
 *            40  70                      10   30 50  70
 *            / \
 *          30  50
 */
void test_rightLeftRotate_given_tree2RL_should_rotate_as_expect(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 30, NULL, NULL, &node30);
  setNode(0, 50, NULL, NULL, &node50);
  setNode(0, 70, NULL, NULL, &node70);
  setNode(0, 40, node30, node50, &node40);
  setNode(0, 60, node40, node70, &node60);
  setNode(0, 20, node10, node60, &node20);
  
  Node *tree = rightLeftRotate(node20);

  TEST_ASSERT_EQUAL_TREE(0, 40, node20, node60, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, node10, node30, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 60, node50, node70, tree->right);
}