#include "Avl.h"
#include "CException.h"
#include "ErrorObject.h"

int avlAdd(Node **rootPtr, Node *newNode)
{
  int valueReturn = 0;
  
  if(!newNode)
    throwError("Hey!The new Node is NULL, cannot add to the tree.", NEWNODE_IS_NULL);
  
  if(!(*rootPtr))
    throwError("Hey!The root is NULL, cannot add newNode to empty tree.", TREE_IS_EMPTY);
  
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
  
  return valueReturn;
    
}