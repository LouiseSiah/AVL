#include "Node.h"

void setNode(int balanceFactor, int data, Node *leftChild, Node *rightChild, Node **root)
{
  if(!(*root))
    *root = (Node *)malloc(sizeof(Node));
  
  (*root)->balanceFactor = balanceFactor;
  (*root)->data = data;
  (*root)->left = leftChild;
  (*root)->right = rightChild;
}

void insertTree(Node **tree, int value)
{
  Node *temp = NULL;
  if(!(*tree))
  {
    temp = (Node *)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->balanceFactor = 0;
    temp->data = value;
    *tree = temp;
    return;
  }
  
  if(value < (*tree)->data)
    insertTree(&(*tree)->left, value);
  else
    insertTree(&(*tree)->right, value);
}

Node *treeBuild(int num, ...)
{
  va_list valist;
  Node *tree = NULL;
  int i;

  /* initialize valist for num number of arguments */
  va_start(valist, num);

  /* access all the arguments assigned to valist */
  for (i = 0; i < num; i++)
  {
    insertTree(&tree, va_arg(valist, int));
  }
  /* clean memory reserved for valist */
  va_end(valist);

  return tree;
}
