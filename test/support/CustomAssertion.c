#include "CustomAssertion.h"

/*
void customTestAssertTree(Node *expectedTree, Node *actualTree, int lineNumber)
{
  if(!actualTree)
  {
    if(expectedTree)
    {
      CUSTOM_TEST_FAIL(lineNumber, "Expected '%d' but actual was NULL.", expectedTree->data);
    }
    else
    {
      return;
    }
  }

  if(!expectedTree)
  {
    if(actualTree)
    {

      CUSTOM_TEST_FAIL(lineNumber,"Expected NULL but actual was '%d'.", actualTree->data);
    }
    else
    {

      return;
    }

  }

  customTestAssertTree(expectedTree->left, actualTree->left, lineNumber);

  if(expectedTree->data != actualTree->data)
    CUSTOM_TEST_FAIL(lineNumber, "Expected '%d' but actual was '%d'.", expectedTree->data, actualTree->data);

  customTestAssertTree(expectedTree->right, actualTree->right, lineNumber);
}
*/

// void customTestAssertTree(int expectedBF, int expectedRoot, int expectedLeftChild, int expectedRightChild, Node *actualTree, int lineNumber)
void customTestAssertTree(int expectedBF, int expectedRoot, Node *expectedLeftChild, Node *expectedRightChild, Node *actualTree, int lineNumber)
{
  if((!expectedRoot) && (actualTree))
    CUSTOM_TEST_FAIL(lineNumber, "Expected the tree was NULL but NOT." );

  if((expectedRoot) && (!actualTree))
    CUSTOM_TEST_FAIL(lineNumber, "Expected the Root was '%d' but actual was NULL", expectedRoot);

  if(expectedRoot != actualTree->data)
    CUSTOM_TEST_FAIL(lineNumber, "Expected the Root was '%d' but actual was '%d'.", expectedRoot, actualTree->data);
  
//******************************************Left Child***********************************************************************

  if((!expectedLeftChild) && (actualTree->left))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Left Child was NULL but actual was '%d'.", actualTree->left->data);

  if((expectedLeftChild) && (!actualTree->left))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Left Child was '%d' but actual was NULL", expectedLeftChild->data);

  if((expectedLeftChild) && (actualTree->left) && ((expectedLeftChild) != (actualTree->left)))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Left Node was not same as actual Left Node");

  if((expectedLeftChild) && (actualTree->left) && (expectedLeftChild->data != actualTree->left->data))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Left Child was '%d' but actual was '%d'.", expectedLeftChild->data, actualTree->left->data);


  
//******************************************Right Child***********************************************************************
 
 if((!expectedRightChild) && (actualTree->right))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Right Child was NULL but actual was '%d'.", actualTree->right->data);

  if((expectedRightChild) && (!actualTree->right))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Right Child was '%d' but actual was NULL", expectedRightChild->data);
  
  if((expectedRightChild) && (actualTree->right) && ((expectedRightChild) != (actualTree->right)))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Right Node was not same as actual Right Node");
  
  if((expectedRightChild) && (actualTree->right) && (expectedRightChild->data != actualTree->right->data))
    CUSTOM_TEST_FAIL(lineNumber, "Expected Right Child was '%d' but actual was '%d'.", expectedRightChild->data, actualTree->right->data);
  
  if(expectedBF != actualTree->balanceFactor)
    CUSTOM_TEST_FAIL(lineNumber, "Expected balance factor '%d' but actual was '%d'.", expectedBF, actualTree->balanceFactor);
}