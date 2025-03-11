#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int A[], int n)
{
  int i, j, temp;

  for (i = 0; i < n; i++)
  {
    j = i - 1;
    temp = A[i];
    while (j >= 0 && temp < A[j])
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = temp;
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
  insertionSort(A, n);
  end = clock();
  display(A, n);
  diff = end - start;
  printf("The time taken is %f second\n", (float)diff / CLOCKS_PER_SEC);
  return 0;
}