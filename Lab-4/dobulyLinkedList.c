#include <stdio.h>
#include <stdlib.h>
struct DLL
{
  int data;
  struct DLL *next;
  struct DLL *prev;
};
struct DLL *first, *last = NULL;
struct DLL *createNode(int element)
{
  struct DLL *NewNode;
  NewNode = (struct DLL *)malloc(sizeof(struct DLL));
  if (NewNode == NULL)
    return NULL;
  else
  {
    NewNode->data = element;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
  }
}
void insertAtBeginning(int element)
{
  struct DLL *NewNode = createNode(element);
  if (NewNode == NULL)
    printf("Cannot allocate memory");
  else
  {
    if (first == NULL)
      first = last = NewNode;
    else
    {
      NewNode->next = first;
      first->prev = NewNode;
      first = NewNode;
    }
    printf("%d was inserted at the beginning\n", first->data);
  }
}
void insertAtTheEnd(int element)
{
  struct DLL *NewNode = createNode(element);
  if (NewNode == NULL)
    printf("Cannot allocate memory");
  else
  {
    if (first == NULL)
      first = last = NewNode;
    else
    {
      last->next = NewNode;
      NewNode->prev = last;
      last = NewNode;
    }
    printf("%d was inserted at the end\n", last->data);
  }
}
int deleteFromBeginning()
{
  struct DLL *temp;
  int element = -1;
  if (first == NULL)
  {
    printf("List is empty\n");
  }
  else if (first->next == NULL)
  {
    temp = first;
    first = last = NULL;
    element = temp->data;
    free(temp);
  }
  else
  {
    temp = first;
    first = first->next;
    first->prev = NULL;
    element = temp->data;
    free(temp);
  }
  return element;
}
int deleteFromEnd()
{
  struct DLL *temp;
  int element = -1;
  if (first == NULL)
  {
    printf("List is empty\n");
  }
  else if (first->next == NULL)
  {
    temp = first;
    first = last = NULL;
    element = temp->data;
    free(temp);
  }
  else
  {
    temp = first;
    while (temp->next != last)
    {
      temp = temp->next;
    }
    temp = last;
    last = last->prev;
    last->next = NULL;
    element = temp->data;
    free(temp);
  }
  return element;
}
void display()
{
  struct DLL *temp;
  if (first == NULL)
  {
    printf("LIST IS EMPTY\n");
  }
  else
  {
    temp = first;
    do
    {
      printf("%d ->", temp->data);
      temp = temp->next;
    } while (temp != NULL);
    printf("NULL\n");
  }
}
void InsertAtSpecificPosition(int position, int element)
{
  if (position < 1)
    printf("Invalid Position\n");
  struct DLL *NewNode = createNode(element);
  struct DLL *temp, *temp1;
  if (NewNode == NULL)
    printf("Cannot allocate memory");
  else if (position == 1)
  {
    insertAtBeginning(element);
  }
  else if (position == last)
  {
    insertAtTheEnd(element);
  }
  else
  {
    temp = first;
    for (int i = 1; i < position - 1; i++)
    {
      temp = temp->next;
    }
    temp1 = temp->next;

    temp->next = NewNode;
    NewNode->prev = temp;
    temp1->prev = NewNode;
    NewNode->next = temp1;

    printf("%d was inserted at the %d position\n", element, position);
  }
}
void DeletionAtSpecificPosition(int position)
{
  if (position < 1)
    printf("Invalid Position\n");
  struct DLL *temp, *temp1;
  if (first == NULL)
    printf("LIST IS EMPTY");
  else if (position == 1)
    deleteFromBeginning();
  else if (position == last)
    deleteFromEnd();
  else
  {
    temp = first;
    for (int i = 1; i < position - 1; i++)
    {
      temp = temp->next;
    }
    if (temp->next == last)
    {
      deleteFromEnd();
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;

    int element = temp1->data;

    printf("%d was deleted at the %d position\n", element, position);
  }
}
int main()
{
  insertAtBeginning(100);
  display();
  insertAtTheEnd(200);
  display();
  insertAtBeginning(500);
  display();

  int data = deleteFromBeginning();
  if (data != -1)
    printf("%d WAS DELETED FROM THE BEGINNING\n", data);
  display();
  data = deleteFromEnd();
  if (data != -1)
    printf("%d WAS DELETED FROM THE END\n", data);
  display();
  InsertAtSpecificPosition(2, 30);
  display();
  InsertAtSpecificPosition(2, 40);
  display();
  DeletionAtSpecificPosition(2);
  return 0;
}
