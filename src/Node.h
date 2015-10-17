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

void insertTree(Node **tree, int value);
Node *setNode(int rootData, Node *leftChild, Node *rightChild);
Node *treeBuild(int num, ...);

#endif // Node_H
