#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void MaxHeapify(int A[], int i, int n)
{
  int left = 2 * i;
  int right = 2 * i + 1;
  int largest = i;

  if (left <= n && A[left] > A[largest])
    largest = left;
  if (right <= n && A[right] > A[largest])
    largest = right;

  if (largest != i)
  {
    int temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    MaxHeapify(A, largest, n);
  }
}

void BuildMaxHeap(int A[], int n)
{
  for (int i = n / 2; i >= 1; i--)
  {
    MaxHeapify(A, i, n);
  }
}

void HeapSort(int A[], int n)
{
  BuildMaxHeap(A, n);
  for (int i = n; i >= 2; i--)
  {

    int temp = A[1];
    A[1] = A[i];
    A[i] = temp;
    n = n - 1;
    MaxHeapify(A, 1, n);
  }
}

void display(int A[], int size)
{

  for (int i = 1; i <= size; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  int A[n + 1];

  srand((unsigned int)time(NULL));

  for (int i = 1; i <= n; i++)
  {
    // A[i] = rand() % 1000;
    A[i] = rand();
  }

  printf("Original array:\n");
  display(A, n);

  printf("Sorting the array using Heap Sort\n");
  clock_t start = clock();
  HeapSort(A, n);
  clock_t end = clock();

  printf("Sorted array:\n");
  display(A, n);

  printf("The time taken is %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}