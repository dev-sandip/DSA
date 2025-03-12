#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linearSearch(int a[], int n, int key)
{
  int i, flag = 0;
  for (i = 0; i < n; i++)
  {
    if (a[i] == key)
    {
      printf("Element found at index %d\n", i);
      return;
    }
  }
  if (flag == 0)
  {
    printf("Element not found\n");
  }
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
  linearSearch(a, n, key);
  end = clock();
  diff = (end - start) / CLOCKS_PER_SEC;
  printf("Time taken for linear search is %f\n", diff);
  return 0;
}