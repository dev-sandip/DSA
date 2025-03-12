#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarySearch(int a[], int n, int key)
{
  int low = 0, high = n - 1, mid;
  while (low <= high)
  {
    mid = low + (high - low) / 2;
    if (a[mid] == key)
    {
      printf("Element found at index %d\n", mid);
      return;
    }
    else if (a[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  printf("Element not found\n");
}
int main()
{
  int a[100], n, key;
  float start, end, diff;
  printf("Enter the number of elements in the array\n");
  scanf("%d", &n);
  printf("Enter the elements of the array\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("Enter the element to be searched\n");

  scanf("%d", &key);
  start = clock();
  binarySearch(a, n, key);
  end = clock();
  diff = (end - start) / CLOCKS_PER_SEC;
  printf("Time taken for binary search is %f\n", diff);
  return 0;
}