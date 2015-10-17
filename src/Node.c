#include "Node.h"

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

Node *setNode(int rootData, Node *leftChild, Node *rightChild)
{
  Node *tree = malloc(sizeof(Node));
  
  
  if(!leftChild);
    tree->left = NULL;
    
  if(!rightChild);
    tree->right = NULL;
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
    //stackPush(stack, va_arg(valist, void*));
  }
  /* clean memory reserved for valist */
  va_end(valist);

  return tree;
}
