#include "Rotation.h"
#include <stdlib.h>
#include "CException.h"
#include "ErrorObject.h"

/*
 * brief @ Right child of a tree will be rotate with the root as shown as below.
 *            Before                             After
 *            20                                  40
 *          /   \                               /   \
 *         10     40                           20     50
 *               / \                         /  \
 *              30  50                     10   30
 *
 * brief @ It will throw an Error when the tree is empty or the tree had no right child.
 * param @ tree    - The tree that is going to rotate its right child.
 * retval@ Node *  - The tree that its right child had been rotated.
 */ 
Node *leftRotate(Node *tree)
{
  if(!tree)
   throwError("Hey!The tree is NULL, nothing to rotate.", TREE_IS_EMPTY);
  
  if(!(tree->right))
    throwError("Hey! There is no Child to rotate.", NO_CHILD_TO_ROTATE);
  
  Node *oldRoot = tree;
  Node *rightLeft = tree->right->left;
  
  tree = tree->right;
  tree->left = oldRoot;
  tree->left->right = rightLeft;
  
  return tree;
} 

/*
 * brief @ Left child of a tree will be rotate with the root as shown as below.
 *             Before                             After
 *              40                                  20
 *             /   \                               /    \
 *            20    50                            10     40
 *           / \                                        /   \
 *         10  30                                      30   50
 *
 * brief @ It will throw an Error when the tree is empty or the tree had no left child.
 * param @ tree    - The tree that is going to rotate its right child.
 * retval@ Node *  - The tree that its right child had been rotated.
 */ 
Node *rightRotate(Node *tree)
{
  if(!tree)
    throwError("Hey!The tree is NULL, nothing to rotate.", TREE_IS_EMPTY);
  
  if(!(tree->left))
    throwError("Hey! There is no Child to rotate.", NO_CHILD_TO_ROTATE);
  
  Node *oldRoot = tree;
  Node *leftRight = tree->left->right;
  
  tree = tree->left;
  tree->right = oldRoot;
  tree->right->left = leftRight;
  
  return tree;
}

/*
 * brief @ Double rotate the right child of left node of a tree. A left rotation will be done first follow by a right rotation.
 *             Before                             After
 *              60                                  40
 *             /   \                                /  \
 *           20     70                           20     60
 *          / \                                /  \    / \
 *         10  40                             10    30 50  70
 *        / \
 *      30  50
 *
 * brief @ It will throw an Error when the tree is empty or the tree had no left child or no right child of left node.
 * param @ tree    - The tree that is going to rotate its children.
 * retval@ Node *  - The tree that its children had been rotated.
 */ 
Node *leftRightRotate(Node *tree)
{
   if(!tree)
    throwError("Hey!The tree is NULL, nothing to rotate.", TREE_IS_EMPTY);
  
  if(!(tree->left))
    throwError("Hey! There is no Child to rotate.", NO_CHILD_TO_ROTATE);
  
  if(!(tree->left->right))
    throwError("Hey! There is no Child to rotate.", NO_CHILD_TO_ROTATE);
  
  Node *newRight = tree;
  Node *newLeft = tree->left;
  Node *newLeftRight = tree->left->right->left;
  Node *newRightLeft = tree->left->right->right;
  
  tree = tree->left->right;
  tree->left = newLeft;
  tree->right = newRight;
  tree->left->right = newLeftRight;
  tree->right->left = newRightLeft;
  
  return tree;
}

/*
 * brief @ Double rotate the right child of left node of a tree. A right rotation will be done first follow by a left rotation.
/*          Before                             After
 *           20                                  40
 *         /   \                                /  \
 *       10     60                           20     60
 *              / \                         /  \    / \
 *            40  70                      10   30 50  70
 *            / \
 *          30  50
 *
 * brief @ It will throw an Error when the tree is empty or the tree had no right child or no left child of right node.
 * param @ tree    - The tree that is going to rotate its children.
 * retval@ Node *  - The tree that its children had been rotated.
 */ 
Node *rightLeftRotate(Node *tree)
{
  if(!tree)
    throwError("Hey!The tree is NULL, nothing to rotate.", TREE_IS_EMPTY);
  
  if(!(tree->right))
    throwError("Hey! There is no Child to rotate.", NO_CHILD_TO_ROTATE);
  
  if(!(tree->right->left))
    throwError("Hey! There is no Child to rotate.", NO_CHILD_TO_ROTATE);
  
  Node *newLeft = tree;
  Node *newRight = tree->right;
  Node *newLeftRight = tree->right->left->left;
  Node *newRightLeft = tree->right->left->right;
  
  tree = tree->right->left;
  tree->left = newLeft;
  tree->right = newRight;
  tree->left->right = newLeftRight;
  tree->right->left = newRightLeft;
  
  return tree;
}