#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void hashSearching(int a[], int n, int key)
{
  int hash[100] = {0};
  for (int i = 0; i < n; i++)
  {
    hash[a[i]] = i;
  }
  if (hash[key] != 0)
  {
    printf("Element found at index %d\n", hash[key]);
  }
  else
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
  hashSearching(a, n, key);
  end = clock();
  diff = (end - start) / CLOCKS_PER_SEC;
  printf("Time taken for hash search is %f\n", diff);
  return 0;
}