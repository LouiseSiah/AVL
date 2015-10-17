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

/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *       NULL NULL             NULL NULL
 */
void test_leftRotate_given_tree1_should_not_rotate(void)
{
  Node *tree = NULL;
  insertTree(&tree, 30);
  tree = leftRotate(tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree);
}

/*          Before               After
 *          30                    40
 *         /  \                  /  \
 *       NULL 40               30   NULL
 */
void test_leftRotate_given_tree2_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(2, 30, 40);
  tree = leftRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 40, 30, 0, tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree->left);
}

/*          Before                             After
 *          30                                40
 *         /  \                              /  \
 *       20    40                           30   NULL
 *                                         / \
 *                                       20  NULL
 */
void test_leftRotate_given_tree3_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(3, 30, 40, 20);
  tree = leftRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 40, 30, 0, tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 20, 0, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 20, 0, 0, tree->left->left);
}

/*          Before                             After
 *           30                                  40
 *         /   \                               /   \
 *       20     40                           30     50
 *      / \    / \                         /  \    / \
 *    10  25  35  50                     20   35  45  60
 *           / \  / \                   / \   / \
 *         33 38 45 60                10  25 33 38
 */
void test_leftRotate_given_tree4_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(11, 30, 20, 10, 25, 40, 50, 35, 33, 38, 45, 60);
  tree = leftRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 40, 30, 50, tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 20, 35, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 20, 10, 25, tree->left->left);
  TEST_ASSERT_EQUAL_TREE(0, 10, 0, 0, tree->left->left->left);
  TEST_ASSERT_EQUAL_TREE(0, 25, 0, 0, tree->left->left->right);
  TEST_ASSERT_EQUAL_TREE(0, 35, 33, 38, tree->left->right);
  TEST_ASSERT_EQUAL_TREE(0, 33, 0, 0, tree->left->right->left);
  TEST_ASSERT_EQUAL_TREE(0, 38, 0, 0, tree->left->right->right);
  TEST_ASSERT_EQUAL_TREE(0, 50, 45, 60, tree->right);
  TEST_ASSERT_EQUAL_TREE(0, 45, 0, 0, tree->right->left);
  TEST_ASSERT_EQUAL_TREE(0, 60, 0, 0, tree->right->right);
}

void test_rightRotate_given_NULL_tree_should_return_NULL(void)
{
  Node *tree = NULL;
  tree = rightRotate(tree);
  TEST_ASSERT_NULL(tree);
}

/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *       NULL NULL             NULL NULL
 */
void test_rightRotate_given_tree1_should_not_rotate(void)
{
  Node *tree = NULL;
  insertTree(&tree, 30);
  tree = rightRotate(tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree);
}

/*          Before               After
 *          40                    30
 *         /  \                  /  \
 *       30  NULL             NULL   40
 */
void test_rightRotate_given_tree2A_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(2, 30, 40);
  tree = rightRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 40, tree);
  TEST_ASSERT_EQUAL_TREE(0, 40, 0, 0, tree->right);
}

/*          Before                             After
 *          30                                20
 *         /  \                              /  \
 *       20    40                         NULL   30
 *                                               / \
 *                                            NULL 40
 */
void test_rightRotate_given_tree3_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(3, 30, 40, 20);
  tree = rightRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 20, 0, 30, tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 40, tree->right);
  TEST_ASSERT_EQUAL_TREE(0, 40, 0, 0, tree->right->right);
}

/*          Before                             After
 *           30                                  20
 *         /   \                               /    \
 *       20     40                           10      30
 *      / \    / \                         /  \    /   \
 *    10  25  35  50                      3   18  25   40
 *   / \  / \                                    / \   / \
 *  3  18 23 28                                 23  28 35 50
 */
void test_rightRotate_given_tree4A_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(11, 30, 20, 10, 3, 18, 25, 23, 28, 40, 35, 50);
  tree = rightRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 20, 10, 30, tree);
  TEST_ASSERT_EQUAL_TREE(0, 10, 3, 18, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 3, 0, 0, tree->left->left);
  TEST_ASSERT_EQUAL_TREE(0, 18, 0, 0, tree->left->right);
  TEST_ASSERT_EQUAL_TREE(0, 30, 25, 40, tree->right);
  TEST_ASSERT_EQUAL_TREE(0, 25, 23, 28, tree->right->left);
  TEST_ASSERT_EQUAL_TREE(0, 23, 0, 0, tree->right->left->left);
  TEST_ASSERT_EQUAL_TREE(0, 28, 0, 0, tree->right->left->right);
  TEST_ASSERT_EQUAL_TREE(0, 40, 35, 50, tree->right->right);
  TEST_ASSERT_EQUAL_TREE(0, 35, 0, 0, tree->right->right->left);
  TEST_ASSERT_EQUAL_TREE(0, 50, 0, 0, tree->right->right->right);
}

void test_leftRightRotate_given_NULL_tree_should_return_NULL(void)
{
  Node *tree = NULL;
  tree = leftRightRotate(tree);
  TEST_ASSERT_NULL(tree);
}

/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *       NULL NULL             NULL NULL
 */
void test_leftRightRotate_given_tree1_should_not_rotate(void)
{
  Node *tree = NULL;
  insertTree(&tree, 30);
  tree = leftRightRotate(tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree);
}

/*          Before               After
 *          40                    40
 *         /  \                  /  \
 *       30  NULL             30   NULL
 */
void test_leftRightRotate_given_tree2A_should_not_rotate(void)
{
  Node *tree = treeBuild(2, 40, 30);
  tree = leftRightRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 40, 30, 0, tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree->left);
}

/*          Before                             After
 *          30                                30
 *         /  \                              /  \
 *       20    40                          20    40
 */
void test_leftRightRotate_given_tree3A_should_not_rotate(void)
{
  Node *tree = treeBuild(3, 30, 20, 40);
  tree = leftRightRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 30, 20, 40, tree);
  // TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree->left);
}

/*          Before                             After
 *           30                                  35
 *         /   \                                /  \
 *       20     40                           30     40
 *              / \                         /  \   / \
 *            35  50                     20    33 38  50
 *           / \                 
 *         33 38
 */
void test_leftRightRotate_given_tree4A_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(7, 30, 20, 40, 50, 35, 33, 38);
  tree = leftRightRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 35, 30, 40, tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 20, 33, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 40, 38, 50, tree->right);
}

void test_rightLeftRotate_given_NULL_tree_should_return_NULL(void)
{
  Node *tree = NULL;
  tree = rightLeftRotate(tree);
  TEST_ASSERT_NULL(tree);
}

/*          Before               After
 *          30                    30
 *         /  \                  /  \
 *       NULL NULL             NULL NULL
 */
void test_rightLeftRotate_given_tree1_should_not_rotate(void)
{
  Node *tree = NULL;
  insertTree(&tree, 30);
  tree = rightLeftRotate(tree);
  TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree);
}

/*          Before               After
 *          40                    40
 *         /  \                  /  \
 *      NULL  50               NULL  50    
 */
void test_rightLeftRotate_given_tree2A_should_not_rotate(void)
{
  Node *tree = treeBuild(2, 40, 50);
  tree = rightLeftRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 40, 0, 50, tree);
  TEST_ASSERT_EQUAL_TREE(0, 50, 0, 0, tree->right);
}

/*          Before                             After
 *          30                                30
 *         /  \                              /  \
 *       20    40                          20    40
 */
void test_rightLeftRotate_given_tree3A_should_not_rotate(void)
{
  Node *tree = treeBuild(3, 30, 20, 40);
  tree = rightLeftRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 30, 20, 40, tree);
  // TEST_ASSERT_EQUAL_TREE(0, 30, 0, 0, tree->left);
}

/*          Before                             After
 *           30                                  25
 *         /   \                                /  \
 *       20     40                           20     30
 *      / \                                /  \    / \
 *    10  25                             10    23 28  40
 *       / \                 
 *     23  28
 */
void test_rightLeftRotate_given_tree4A_should_rotate_as_expect(void)
{
  Node *tree = treeBuild(7, 30, 20, 10, 40, 25, 23, 28);
  tree = rightLeftRotate(tree);

  TEST_ASSERT_EQUAL_TREE(0, 25, 20, 30, tree);
  TEST_ASSERT_EQUAL_TREE(0, 20, 10, 23, tree->left);
  TEST_ASSERT_EQUAL_TREE(0, 30, 28, 40, tree->right);
}