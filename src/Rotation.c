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