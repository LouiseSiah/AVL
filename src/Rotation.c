#include "Rotation.h"
#include <stdlib.h>

Node *leftRotate(Node *tree)
{
  if(!tree)
    return NULL;
  
  if(!(tree->right))
    return tree;
  
  Node *oldRoot = tree;
  Node *rightLeft = tree->right->left;
  
  tree = tree->right;
  tree->left = oldRoot;
  tree->left->right = rightLeft;
  
  return tree;
} 

Node *rightRotate(Node *tree)
{
  if(!tree)
    return NULL;
  
  if(!(tree->left))
    return tree;
  
  Node *oldRoot = tree;
  Node *leftRight = tree->left->right;
  
  tree = tree->left;
  tree->right = oldRoot;
  tree->right->left = leftRight;
  
  return tree;
}

Node *leftRightRotate(Node *tree)
{
   if(!tree)
    return NULL;
  
  if(!(tree->left))
    return tree;
  
  if(!(tree->left->right))
    return tree;
  
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

Node *rightLeftRotate(Node *tree)
{
  if(!tree)
    return NULL;
  
  if(!(tree->right))
    return tree;
  
  if(!(tree->right->left))
    return tree;
  
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