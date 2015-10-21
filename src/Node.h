#ifndef Node_H
#define Node_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node_t Node;

struct Node_t
{
  Node *left;
  Node *right;
  int balanceFactor;
  int data;  
};

// void setNode(int balanceFactor, int data, Node *leftChild, Node *rightChild, Node **root);

void setNode(int balanceFactor, int data, Node *leftChild, Node *rightChild, Node *root);

#endif // Node_H
