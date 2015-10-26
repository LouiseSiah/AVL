#include "Avl.h"

int avlAdd(Node **rootPtr, Node *newNode)
{
  // Node *temp = NULL;
  int valueReturn = 0;
  
  // if(!(*rootPtr))
  // {
    // // (*rootPtr) = (Node *)malloc(sizeof(Node));
    // // (*rootPtr)->left = (*rootPtr)->right = NULL; 
    // (*rootPtr) = newNode;
    // return 0 ;
  // }
  
  if(newNode->data < (*rootPtr)->data)
  {
    if(!(*rootPtr)->left)
    {
      (*rootPtr)->balanceFactor--;
      (*rootPtr)->left = newNode;
      if((*rootPtr)->balanceFactor == -1)
        return 1;
    }
    else
    {
      (*rootPtr)->balanceFactor--;
      valueReturn = avlAdd(&(*rootPtr)->left, newNode);
    }

  }
  else
  {
    if(!(*rootPtr)->right)
    {
      (*rootPtr)->balanceFactor++;
      (*rootPtr)->right = newNode;
      if((*rootPtr)->balanceFactor == 1)
        return 1;
    }
    else
    {
      (*rootPtr)->balanceFactor++;
      valueReturn = avlAdd(&(*rootPtr)->right, newNode);
    }
  }
  
  if(valueReturn)
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