#ifndef ErrorObject_H
#define ErrorObject_H
// #include <stdarg.h>

typedef enum
{
  TREE_IS_EMPTY,
  NO_CHILD_TO_ROTATE,
  NEWNODE_IS_NULL, // for function :int avlAdd(Node **rootPtr, Node *newNode)
} ErrorCode;

typedef struct
{
  char *errorMsg;
  ErrorCode errorCode;
} ErrorObject;

void throwError(char *message,ErrorCode errCode);
void freeError(ErrorObject *errObj);

#endif // ErrorObject_H
