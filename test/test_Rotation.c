#include "unity.h"
#include "Rotation.h"
#include "CustomAssertion.h"
#include "Node.h"
#include "ErrorObject.h"
#include "CException.h"

Node node10, node20, node30, node40, node50, node60, node70, node80, node90, node100;

void setUp(void){}

void tearDown(void){}

void test_leftRotate_given_NULL_tree_should_catch_the_error(void)
{
  Node *tree = NULL;
  ErrorObject *err;
  Try
  {
    tree = leftRotate(tree);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_EMPTY, err->errorCode);

    freeError(err);
  }
}

/*          Before               After
 *        30(-1)                 30(-1)
 *         /  \                  /  \
 *       20  NULL              20  NULL
 */
void test_leftRotate_given_tree1_should_catch_the_error(void)
{
  setNode(0, 20, NULL, NULL, &node20);
  setNode(-1, 30, &node20, NULL, &node30);
  ErrorObject *err;
  Try
  {
    Node *tree = leftRotate(&node30);
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
 *           20(+2)                            40(0)
 *             \                               /   \
 *            40(+1)                       20(0)  50(0)
 *              \
 *              50(0)
 */
void test_leftRotate_given_balanceFactor_of_rightChild_is_1_should_rotate_as_expect_and_give_correct_balance_factor(void)
{
  setNode(0, 50, NULL, NULL, &node50);
  setNode(1, 40, NULL, &node50, &node40);
  setNode(2, 20, NULL, &node40, &node20);

  Node *tree = leftRotate(&node20);

  TEST_ASSERT_EQUAL_TREE(0, 40, &node20, &node50, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, NULL, NULL, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 50, NULL, NULL, tree->right);
}

/*          Before                             After
 *         20(+2)                               60(-1)
 *            \                               /    \
 *           60(0)                        20(+1)    90(0)
 *          /    \                           \
 *       40(0)   90(0)                       40(0)
 *
 */
void test_leftRotate_given_balanceFactor_of_rightChild_is_0_should_rotate_as_expect_and_give_correct_balance_factor(void)
{
  setNode(0, 40, NULL, NULL, &node40);
  setNode(0, 90, NULL, NULL, &node90);
  setNode(0, 60, &node40, &node90, &node60);
  setNode(2, 20, NULL, &node60, &node20);

  Node *tree = leftRotate(&node20);

  TEST_ASSERT_EQUAL_TREE(-1, 60, &node20, &node90, tree);
  TEST_ASSERT_EQUAL_TREE(1, 20, NULL, &node40, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 40, NULL, NULL, tree->left->right);
  TEST_ASSERT_EQUAL_TREE(0, 90, NULL, NULL, tree->right);
}

void test_rightRotate_given_NULL_tree_should_catch_the_error(void)
{
  Node *tree = NULL;
  ErrorObject *err;
  Try
  {
    tree = rightRotate(tree);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_EMPTY, err->errorCode);

    freeError(err);
  }
}

/*          Before               After
 *        30(+1)                  30(+1)
 *         /  \                  /  \
 *      NULL  20(0)          NULL   20(0)
 */
void test_rightRotate_given_tree1_should_catch_the_error(void)
{
  setNode(0, 20, NULL, NULL, &node20);
  setNode(1, 30, NULL, &node20, &node30);
  ErrorObject *err;
  Try
  {
    Node *tree = rightRotate(&node30);
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
 *           50(-2)                           40(0)
 *           /                               /   \
 *         40(-1)                        20(0)  50(0)
 *         /
 *        20(0)
 */
void test_rightRotate_given_balanceFactor_of_leftChild_is_minus1_should_rotate_as_expect_and_give_correct_balance_factor(void)
{
  setNode(0, 20, NULL, NULL, &node20);
  setNode(-1, 40, &node20, NULL, &node40);
  setNode(-2, 50, &node40, NULL, &node50);

  Node *tree = rightRotate(&node50);

  TEST_ASSERT_EQUAL_TREE(0, 40, &node20, &node50, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, NULL, NULL, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 50, NULL, NULL, tree->right);
}

/*          Before                             After
 *         70(-2)                             30(+1)
 *        /                                   /   \
 *      30(0)                              10(0)  70(-1)
 *     /   \                                     /
 *  10(0) 40(0)                              40(0)
 */
void test_rightRotate_given_balanceFactor_of_leftChild_is_0_should_rotate_as_expect_and_give_correct_balance_factor(void)
{
  setNode(0, 10, NULL, NULL, &node10);
  setNode(0, 40, NULL, NULL, &node40);
  setNode(0, 30, &node10, &node40, &node30);
  setNode(-2, 70, &node30, NULL, &node70);

  Node *tree = rightRotate(&node70);

  TEST_ASSERT_EQUAL_TREE(1, 30, &node10, &node70, tree);
  TEST_ASSERT_EQUAL_TREE(0, 10, NULL, NULL, tree->left);
  TEST_ASSERT_EQUAL_TREE(-1, 70, &node40, NULL, tree->right);
  TEST_ASSERT_EQUAL_TREE(0, 40, NULL, NULL, tree->right->left);
}


void test_leftRightRotate_given_NULL_tree_should_catch_the_error(void)
{
  Node *tree = NULL;
  ErrorObject *err;
  Try
  {
    tree = leftRightRotate(tree);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_EMPTY, err->errorCode);

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
    Node *tree = leftRightRotate(&node30);
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
  setNode(0, 30, &node20, NULL, &node30);

  ErrorObject *err;
  Try
  {
    Node *tree = leftRightRotate(&node30);
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
  setNode(0, 40, &node30, &node50, &node40);
  setNode(0, 20, &node10, &node40, &node20);
  setNode(0, 60, &node20, &node70, &node60);

  Node *tree = leftRightRotate(&node60);

  TEST_ASSERT_EQUAL_TREE(0, 40, &node20, &node60, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, &node10, &node30, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 60, &node50, &node70, tree->right);
}

void test_rightLeftRotate_given_NULL_tree_should_catch_the_error(void)
{
  Node *tree = NULL;
  ErrorObject *err;
  Try
  {
    tree = rightLeftRotate(tree);
    TEST_FAIL_MESSAGE("Expected to catch Error here, but didn't.\n");
  }
  Catch(err)
  {
    TEST_ASSERT_EQUAL_STRING("Hey!The tree is NULL, nothing to rotate.", err->errorMsg);
    TEST_ASSERT_EQUAL(TREE_IS_EMPTY, err->errorCode);

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
    Node *tree = rightLeftRotate(&node30);
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
  setNode(0, 30, NULL, &node20, &node30);
  ErrorObject *err;
  Try
  {
    Node *tree = rightLeftRotate(&node30);
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
  setNode(0, 40, &node30, &node50, &node40);
  setNode(0, 60, &node40, &node70, &node60);
  setNode(0, 20, &node10, &node60, &node20);

  Node *tree = rightLeftRotate(&node20);

  TEST_ASSERT_EQUAL_TREE(0, 40, &node20, &node60, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, &node10, &node30, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 60, &node50, &node70, tree->right);
}