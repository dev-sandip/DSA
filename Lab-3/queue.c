#include <stdio.h>
#define MAX 5
struct CircularQueue
{
  int FRONT;
  int REAR;
  int Data[MAX];
};
typedef struct CircularQueue CQ;
void enqueue(CQ *Q, int element)
{
  if (Q->FRONT == (Q->REAR + 1 % MAX))
    printf("Queue is FULL\n");
  else
  {
    Q->Data[Q->REAR] = element;
    Q->REAR = (Q->REAR + 1) % MAX;
    printf("%d is ENQUEUE!\n", element);
  }
}
int dequeue(CQ *Q)
{

  int element = -1;
  if (Q->FRONT == Q->REAR)
    printf("Queue is Empty\n");
  else
  {
    element = Q->Data[Q->FRONT];
    Q->FRONT = (Q->FRONT + 1) % MAX;
  }
  return element;
}
int main()
{
  int choice, data;
  CQ Q = {0, 0};
  do
  {
    printf("1.ENQUEUE\n 2.DEQUEUE\n 3.Exit\n");
    printf("Choice? ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Element?\n");
      scanf("%d", &data);
      enqueue(&Q, data);
      break;
    case 2:
      data = dequeue(&Q);
      if (data != -1)
      {
        printf("DEQUEUED element is %d\n", data);
      }

      break;
    case 3:
      printf("BYE!\n");
      break;
    }
  } while (choice != 3);
  return 0;
}