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

  //double rotation: rightLeftRotate()
  if(((*rootPtr)->balanceFactor == 2) && ((*rootPtr)->right->balanceFactor == -1))
  {
    *rootPtr = rightLeftRotate(*rootPtr);
    
    if((*rootPtr)->balanceFactor == 1)
    {
      (*rootPtr)->left->balanceFactor = -1;
      (*rootPtr)->right->balanceFactor = 0;
      (*rootPtr)->balanceFactor = 0;
    }
    else if((*rootPtr)->balanceFactor == -1)
    {
      (*rootPtr)->left->balanceFactor = 0;
      (*rootPtr)->right->balanceFactor = 1;
      (*rootPtr)->balanceFactor = 0;
    }
    else
    {
      (*rootPtr)->left->balanceFactor = 0;
      (*rootPtr)->right->balanceFactor = 0;
      (*rootPtr)->balanceFactor = 0;
    }
        
  }

  //single rotation: leftRotate()
  if(((*rootPtr)->balanceFactor == 2) && (((*rootPtr)->right->balanceFactor == 1) ||  ((*rootPtr)->right->balanceFactor == 0)) )
  {
    *rootPtr = leftRotate(*rootPtr);
    if((*rootPtr)->balanceFactor)
      (*rootPtr)->left->balanceFactor-= 2;
    else
      (*rootPtr)->left->balanceFactor--;

    (*rootPtr)->balanceFactor--;
  }
  
  //double rotation: leftRightRotate()
  if(((*rootPtr)->balanceFactor == -2) && ((*rootPtr)->left->balanceFactor == 1))
  {
    *rootPtr = leftRightRotate(*rootPtr);
    
    if((*rootPtr)->balanceFactor == -1)
    {
      (*rootPtr)->right->balanceFactor = 1;
      (*rootPtr)->left->balanceFactor = 0;
      (*rootPtr)->balanceFactor = 0;
    }
    else if((*rootPtr)->balanceFactor == 1)
    {
      (*rootPtr)->right->balanceFactor = 0;
      (*rootPtr)->left->balanceFactor = -1;
      (*rootPtr)->balanceFactor = 0;
    }
    else
    {
      (*rootPtr)->left->balanceFactor = 0;
      (*rootPtr)->right->balanceFactor = 0;
      (*rootPtr)->balanceFactor = 0;
    }
  }

  //single rotation: righttRotate()    
  if(((*rootPtr)->balanceFactor == -2) && (((*rootPtr)->left->balanceFactor == -1) || ((*rootPtr)->left->balanceFactor == 0)))
  {
    *rootPtr = rightRotate(*rootPtr);
    if((*rootPtr)->balanceFactor == -1)
      (*rootPtr)->right->balanceFactor+= 2;
    else
      (*rootPtr)->right->balanceFactor++;  

    (*rootPtr)->balanceFactor++;

  }
    
  if( (!bFBefore) &&  (((*rootPtr)->balanceFactor == 1) || ((*rootPtr)->balanceFactor == -1)) )
    return 1;

  return 0;

}
