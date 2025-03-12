#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define true 1
#define false 0
struct Linear_queue
{
  int front;
  int rear;
  int data[MAX];
};
typedef struct Linear_queue LQ;
// int isFull(LQ *s)
// {
//     if (s->rear == MAX - 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int isEmpty(LQ *s)
// {
//     if (s->front > s->rear)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
void enqueue(LQ *s, int element)
{
  if (s->rear == MAX - 1)
  {
    printf("Queue is full\n");
  }
  else
  {
    s->rear++;
    s->data[s->rear] = element;
    printf("%d was enqueued.\n", element);
  }
}
int dequeue(LQ *s)
{
  int element = -1;
  if (s->front > s->rear)
  {
    printf("Queue is empty\n");
  }
  else
  {
    element = s->data[s->front];
    s->front++;
  }
  return element;
}
int checkRear(LQ *s)
{
  return s->data[s->rear];
}
int checkFront(LQ *s)
{
  return s->data[s->front];
}
int main()
{
  int choice, data;
  LQ s = {0, 0}; // Initialize FRONT and REAR to 0
  do
  {
    printf("\n1. ENQUEUE\n2. DEQUEUE\n 3.CheckRear\n 4.checkFront\n5. EXIT\n");
    printf("Choice? ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the element: ");
      scanf("%d", &data);
      enqueue(&s, data);
      break;
    case 2:
      data = dequeue(&s);
      if (data != -1)
      {
        printf("Dequeued element is %d.\n", data);
      }
      break;
    case 3:
      printf("Rear is  %d\n", checkRear(&s));
      break;
    case 4:
      printf("Front is  %d\n", checkFront(&s));
      break;
    case 5:
      printf("Bye!!!\n");
      break;
    default:
      printf("Please enter a valid choice!\n");
      break;
    }
  } while (choice != 5);
  return 0;
}
