#include "Rotation.h"
#include <stdlib.h>

Node *leftRotate(Node *tree)
{
  Node *newTree = malloc(sizeof(Node));
  newTree->weight = 0;
  newTree->data = tree->right->data;
  newTree->left->data = tree->data;
  newTree->right = tree->right->right;
  newTree->left->left = tree->left;
  newTree->left->right = tree->right->left;
  
  return newTree;
}