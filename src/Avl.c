#include "Avl.h"

int avlAdd(Node **rootPtr, Node *newNode)
{
  // Node *temp = NULL;
  // int beforeBF = (*rootPtr)->balanceFactor;
  int balanceFactor = 1;// = (*rootPtr)->balanceFactor;
  if(!(*rootPtr))
  {
    // (*rootPtr) = (Node *)malloc(sizeof(Node));
    // (*rootPtr)->left = (*rootPtr)->right = NULL; 
    (*rootPtr) = newNode;
    return 0 ;
  }
  
  if(newNode->data < (*rootPtr)->data)
  {
    (*rootPtr)->balanceFactor--;
    balanceFactor = avlAdd(&(*rootPtr)->left, newNode);

  }
  else
  {
    (*rootPtr)->balanceFactor++;
    balanceFactor = avlAdd(&(*rootPtr)->right, newNode);
  }
  
  if((!balanceFactor) && (((*rootPtr)->balanceFactor) || ((*rootPtr)->balanceFactor == -1)))
    return 1;
  else
    return 0;
    
}
  // if(!balanceFactor)
    // return 0;
  // else
    // return 1;
// }


// void insertTree(Node **tree, int value)
// {
  // Node *temp = NULL;
  // if(!(*tree))
  // {
    // temp = (Node *)malloc(sizeof(Node));
    // temp->left = temp->right = NULL;
    // temp->balanceFactor = 0;
    // temp->data = value;
    // *tree = temp;
    // return;
  // }
  
  // if(value < (*tree)->data)
    // insertTree(&(*tree)->left, value);
  // else
    // insertTree(&(*tree)->right, value);
// }