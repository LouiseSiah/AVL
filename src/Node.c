#include "Node.h"

// void setNode(int balanceFactor, int data, Node *leftChild, Node *rightChild, Node **root)
// {
  // if(!(*root))
    // *root = (Node *)malloc(sizeof(Node));

  // (*root)->balanceFactor = balanceFactor;
  // (*root)->data = data;
  // (*root)->left = leftChild;
  // (*root)->right = rightChild;
// }

void setNode(int balanceFactor, int data, Node *leftChild, Node *rightChild, Node *root)
{
  // if(!(*root))
    // *root = (Node *)malloc(sizeof(Node));

  root->balanceFactor = balanceFactor;
  root->data = data;
  root->left = leftChild;
  root->right = rightChild;
}