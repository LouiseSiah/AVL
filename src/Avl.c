#include "Avl.h"
#include "CException.h"
#include "ErrorObject.h"
#include "Rotation.h"

int avlAdd(Node **rootPtr, Node *newNode)
{
  int bFBefore;
  int valueReturn = 0;

  if(!newNode)
    throwError("Hey!The new Node is NULL, cannot add to the tree.", NEWNODE_IS_NULL);

  if(!(*rootPtr))
    throwError("Hey!The root is NULL, cannot add newNode to empty tree.", TREE_IS_EMPTY);

  bFBefore = (*rootPtr)->balanceFactor;

  if( (newNode->data < (*rootPtr)->data) && (!(*rootPtr)->left) )
  {
      (*rootPtr)->balanceFactor--;
      (*rootPtr)->left = newNode;
  }

  else if ( (newNode->data < (*rootPtr)->data) && (*rootPtr)->left )
  {
    valueReturn = avlAdd(&(*rootPtr)->left, newNode);
    if(valueReturn)
      (*rootPtr)->balanceFactor--;
  }

  else if ( (newNode->data > (*rootPtr)->data) && (!(*rootPtr)->right) )
  {
    (*rootPtr)->balanceFactor++;
    (*rootPtr)->right = newNode;
  }

  else if ( (newNode->data > (*rootPtr)->data) && (*rootPtr)->right ) 
  {
    valueReturn = avlAdd(&(*rootPtr)->right, newNode);
    if(valueReturn)
      (*rootPtr)->balanceFactor++;
  }

  if((*rootPtr)->balanceFactor == 2)
  {
    if((*rootPtr)->right->balanceFactor == -1)
      printf("hello\n");
    else;
     *rootPtr = leftRotate(*rootPtr);
  }
  
  if((*rootPtr)->balanceFactor == -2)
  {
    if((*rootPtr)->left->balanceFactor == 1)
      printf("hello\n");
    else;
     *rootPtr = rightRotate(*rootPtr);
  }
    
  if( (!bFBefore) &&  (((*rootPtr)->balanceFactor == 1) || ((*rootPtr)->balanceFactor == -1)) )
    return 1;

  return 0;

}
