#ifndef CustomAssertion_H
#define CustomAssertion_H
#include "unity.h"
#include "Node.h"
// #include <assert.h>

// ... can represent any arguement.
#define CUSTOM_TEST_FAIL(lineNo, msg, ...)                                                        \
                {                                                                                 \
                  char buffer[256];                                                               \
                  sprintf(buffer, msg, ## __VA_ARGS__);                                           \
                  UNITY_TEST_FAIL(lineNo, buffer);                                                 \
                }

#define TEST_ASSERT_EQUAL_TREE(expectedBF, expectedRoot, expectedLeftChild, expectedRightChild, actualTree);  \
         customTestAssertTree(expectedBF, expectedRoot, expectedLeftChild, expectedRightChild, actualTree, __LINE__);

void customTestAssertTree(int expectedBF, int expectedRoot, Node *expectedLeftChild, Node *expectedRightChild, Node *actualTree, int lineNumber);

#endif // CustomAssertion_H
