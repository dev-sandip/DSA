// singly linked list
// linked list as an adt
#include <stdio.h>
#include <stdlib.h>
struct SLL
{
  int data;
  struct SLL *next;
};
typedef struct SLL nodeType;
nodeType *First, *Last = NULL;
void insertAtFirst(int data)
{
  nodeType *newNode;
  newNode = (nodeType *)malloc(sizeof(nodeType));
  newNode->data = data;
  newNode->next = NULL;
  if (First == NULL)
  {
    First = newNode;
    Last = newNode;
  }
  else
  {
    newNode->next = First;
    First = newNode;
  }
};
void insertAtLast(int data)

{
  nodeType *newNode;
  newNode = (nodeType *)malloc(sizeof(nodeType));
  newNode->data = data;
  newNode->next = NULL;
  if (First == NULL)
  {
    First = newNode;
    Last = newNode;
  }
  else
  {
    Last->next = newNode;
    Last = newNode;
  }
}
int main()
{

  return 0;
}