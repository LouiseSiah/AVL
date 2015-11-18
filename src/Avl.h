#ifndef Avl_H
#define Avl_H
 #include "Node.h"

int avlAdd(Node **rootPtr, Node *newNode);
Node *avlRemove(Node **rootPtr, int value, int *heightChange);
Node *avlGetReplacer(Node **rootPtr);
#endif // Avl_H
