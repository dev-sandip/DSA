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
void insertAtSpecificPosition(int data, int POS)
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
  if (POS == 1)
  {
    newNode->next = First;
    First = newNode;
  }
  else
  {
    nodeType *temp = First;
    for (int i = 1; i < POS - 1; i++)
    {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void DeleteAtFirst()
{
  if (First == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    nodeType *temp = First;
    First = First->next;
    free(temp);
    printf("Node deleted with data %d\n", temp->data);
  }
}

void DeleteAtLast()
{
  if (First == NULL)
  {
    printf("List is empty\n");
  }
  else if (First->next == NULL)
  {
    nodeType *temp = First;
    First = Last = NULL;
    free(temp);
  }
  else
  {
    nodeType *temp = First;
    while (temp->next != Last)
    {
      temp = temp->next;
    }
    temp = Last;
    temp = temp->next;
    free(temp);
    Last->next = NULL;
    printf("Node deleted with data %d\n", temp->data);
  }
}
void DeleteAtSpecificPosition(int POS)
{
  if (First == NULL)
  {
    printf("List is empty\n");
  }
  if (POS == 1)
  {
    DeleteAtFirst();
  }
  else
  {
    nodeType *temp = First;
    for (int i = 1; i < POS - 1; i++)
    {
      temp = temp->next;
    }
    nodeType *tempp = temp->next;
    temp->next = tempp->next;
    free(tempp);
    printf("Node deleted with data %d\n", tempp->data);
  }
}
void Display()
{
  if (First == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    nodeType *temp = First;
    do
    {
      printf("%d\n", temp->data);
      temp = temp->next;
    } while (temp != NULL);
  }
}
int main()
{
  int choice, position, data;

  while (1)
  {
    printf("1. Insert at first\n");
    printf("2. Insert at last\n");
    printf("3. Insert at specific position\n");
    printf("4. Delete at first\n");
    printf("5. Delete at last\n");
    printf("6. Delete at specific position\n");
    printf("7. Display\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      insertAtFirst(data);
      break;
    case 2:

      printf("Enter data: ");
      scanf("%d", &data);
      insertAtLast(data);
      break;
    case 3:

      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter position: ");
      scanf("%d", &position);
      insertAtSpecificPosition(data, position);
      break;
    case 4:
      DeleteAtFirst();
      break;
    case 5:

      DeleteAtLast();
      break;
    case 6:

      printf("Enter position: ");
      scanf("%d", &position);
      DeleteAtSpecificPosition(position);
      break;
    case 7:
      Display();
      break;
    case 8:
      printf("Exiting the program\n");
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
