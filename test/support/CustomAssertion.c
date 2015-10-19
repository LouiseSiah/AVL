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

void customTestAssertTree(int expectedBF, Node *expectedRoot, Node *expectedLeftChild, Node *expectedRightChild, Node *actualTree, int lineNumber)
{
  if(expectedBF != actualTree->balanceFactor)
    CUSTOM_TEST_FAIL(lineNumber, "Expected balance factor '%d' but actual was '%d'.", expectedBF, actualTree->balanceFactor);
    
  
}
