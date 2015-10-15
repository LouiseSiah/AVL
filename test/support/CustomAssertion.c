#include "CustomAssertion.h"

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
    printf("Expect NULL\n");
    if(actualTree)
      CUSTOM_TEST_FAIL(lineNumber,"Expected NULL but actual was '%d'.", actualTree->data);
  }
  
  customTestAssertTree(expectedTree->left, actualTree->left, lineNumber);
  
  if(expectedTree->data != actualTree->data)
    CUSTOM_TEST_FAIL(lineNumber, "Expected '%d' but actual was '%d'.", expectedTree->data, actualTree->data);
  
  customTestAssertTree(expectedTree->right, actualTree->right, lineNumber);
}