#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void SelectionSort(int A[], int n)
{
  int i, j, pos, least;
  for (i = 0; i < n; i++)
  {
    least = A[i];
    pos = i;
    for (j = i + 1; j < n; j++)
    {
      if (A[i] < least)
      {
        least = A[j];
        pos = j;
      }
    }
  }
}
void display(int A[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}
int main()
{
  int A[100000], n, i;
  clock_t start, end, diff;
  srand(time(NULL));
  printf("Enter n ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    A[i] = rand();
  display(A, n);
  start = clock();
  SelectionSort(A, n);
  end = clock();
  display(A, n);
  diff = end - start;
  printf("The time taken is %f second\n", (float)diff / CLOCKS_PER_SEC);
  return 0;
}