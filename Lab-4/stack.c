// Stack
#include <stdio.h>
#include <stdlib.h>
struct SLL
{
  int data;
  struct SLL *next;
};
struct SLL *top = NULL;
struct SLL *createNode(int element)
{
  struct SLL *NewNode;
  NewNode = (struct SLL *)malloc(sizeof(struct SLL));
  if (NewNode == NULL)
    return NULL;
  else
  {
    NewNode->data = element;
    NewNode->next = NULL;
    return NewNode;
  }
}
void Insertion(int element)
{
  struct SLL *NewNode = createNode(element);
  if (NewNode == NULL)
    printf("Cannot allocate memory");
  else
  {
    if (top == NULL)
      top = NewNode;
    else
    {
      NewNode->next = top;
      top = NewNode;
    }
    printf("%d was inserted at the beginning\n", top->data);
  }
}
void Deletion()
{
  struct SLL *temp;
  int element = -1;
  if (top == NULL)
    printf("Stack is Empty\n");
  else if (top->next == NULL)
  {
    temp = top;
    element = temp->data;
    top = NULL;
    free(temp);
    printf("%d was deleted from stack\n", element);
  }
  else
  {
    temp = top;
    element = temp->data;
    top = top->next;
    free(temp);
    printf("%d was deleted from stack\n", element);
  }
}
void display()
{
  struct SLL *temp;
  if (top == NULL)
  {
    printf("STACK IS EMPTY\n");
  }
  else
  {
    temp = top;
    do
    {
      printf("%d ->", temp->data);
      temp = temp->next;
    } while (temp != NULL);
    printf("NULL\n");
  }
}
int main()
{
  Insertion(10);
  display();
  Insertion(20);
  display();
  Insertion(30);
  display();
  Deletion();
  display();
  Deletion();

  return 0;
}
