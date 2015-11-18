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

  if(newNode->data < (*rootPtr)->data && !(*rootPtr)->left )
  {
      (*rootPtr)->balanceFactor--;
      (*rootPtr)->left = newNode;
  }

  if(newNode->data < (*rootPtr)->data && (*rootPtr)->left )
  {
    valueReturn = avlAdd(&(*rootPtr)->left, newNode);
    if(valueReturn)
      (*rootPtr)->balanceFactor--;
  }

  if(newNode->data > (*rootPtr)->data && !(*rootPtr)->right )
  {
    (*rootPtr)->balanceFactor++;
    (*rootPtr)->right = newNode;
  }

  if(newNode->data > (*rootPtr)->data && (*rootPtr)->right )
  {
    valueReturn = avlAdd(&(*rootPtr)->right, newNode);
    if(valueReturn)
      (*rootPtr)->balanceFactor++;
  }

  //double rotation: rightLeftRotate()
  if((*rootPtr)->balanceFactor == 2 && (*rootPtr)->right->balanceFactor == -1)
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

  //single rotation: rightRotate()
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


Node *avlRemove(Node **rootPtr, int value, int *heightChange)
{
  Node *remove;
  int bFBefore;

  if(!(*rootPtr))
    throwError("Hey!The root is NULL, cannot remove any node from empty tree.", TREE_IS_EMPTY);

  bFBefore = (*rootPtr)->balanceFactor;

  //get in left side
  if(value < (*rootPtr)->data && value != (*rootPtr)->left->data)
  {
    if(!((*rootPtr)->left))
      throwError("Hey!There is no Node that you want to remove.", NO_NODE_TO_REMOVE);//havent test yet

    remove = avlRemove( &((*rootPtr)->left), value, heightChange);

    if(*heightChange)
      (*rootPtr)->balanceFactor++;
  }

  //get in right side
  if(value > (*rootPtr)->data && value != (*rootPtr)->right->data )
  {
    if(!((*rootPtr)->right))
      throwError("Hey!There is no Node that you want to remove.", NO_NODE_TO_REMOVE);//havent test yet

    remove = avlRemove( &((*rootPtr)->right), value, heightChange);

    if(*heightChange)
      (*rootPtr)->balanceFactor--;
  }

  if(value == (*rootPtr)->left->data)
  {
    remove = (*rootPtr)->left;
    (*rootPtr)->left = NULL;
    (*rootPtr)->balanceFactor++;
  }
  else if(value == (*rootPtr)->right->data)
  {
    remove = (*rootPtr)->right;
    (*rootPtr)->right = NULL;
    (*rootPtr)->balanceFactor--;
  }

  //double rotation: rightLeftRotate()
  if((*rootPtr)->balanceFactor == 2 && (*rootPtr)->right->balanceFactor == -1)
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

  if((bFBefore == 1 || bFBefore == -1) &&  !((*rootPtr)->balanceFactor) )
    *heightChange = 1;
  else
    *heightChange = 0;

  return remove;

}

Node *avlGetReplacer(Node **rootPtr)
{
  Node *replacer;

  //the only child option without right child
  if(!(*rootPtr)->left && !(*rootPtr)->right)
  {
    replacer = (*rootPtr);
    *rootPtr = NULL;
  }

  //the only child option WITH child
  else if(!(*rootPtr)->left && (*rootPtr)->right)
  {
    replacer = (*rootPtr);
    *rootPtr = (*rootPtr)->right;
    replacer->right = NULL;
  }
  
  //left child withOUT grandson of this node will be the Replacer
  else if(!(*rootPtr)->left->left && !(*rootPtr)->left->right)
  {
    replacer = (*rootPtr)->left;
    (*rootPtr)->left = NULL;
    (*rootPtr)->balanceFactor++;
  }

  //left child WITH grandson of this node will be the Replacer
  else if(!(*rootPtr)->left->left && (*rootPtr)->left->right)
  {
    replacer = (*rootPtr)->left;
    (*rootPtr)->left = (*rootPtr)->left->right;
    (*rootPtr)->balanceFactor++;
    replacer->right = NULL;
  }

  else if((*rootPtr)->left->left)
  {
    replacer = avlGetReplacer(&((*rootPtr)->left));
  }
  
  //double rotation: rightLeftRotate()
  if((*rootPtr) && (*rootPtr)->right)
  {
    
    if((*rootPtr)->balanceFactor == 2 && (*rootPtr)->right->balanceFactor == -1)
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

  }

  return replacer;
}