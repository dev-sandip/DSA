import random
import time


def merge(arr, left, mid, right):
  L = arr[left:mid + 1]
  R = arr[mid + 1:right + 1]

  i = 0  
  j = 0  
  k = left  

  while i < len(L) and j < len(R):
    if L[i] <= R[j]:
      arr[k] = L[i]
      i += 1
    else:
      arr[k] = R[j]
      j += 1
    k += 1

  while i < len(L):
    arr[k] = L[i]
    i += 1
    k += 1

  while j < len(R):
    arr[k] = R[j]
    j += 1
    k += 1


def merge_sort(arr, left, right):
  if left < right:
    mid = (left + right) // 2
    merge_sort(arr, left, mid)
    merge_sort(arr, mid + 1, right)
    merge(arr, left, mid, right)


def display(arr):
  print(" ".join(map(str, arr)))


# Example usage
n = int(input("Enter the size of the array (e.g., 10): "))
arr = [random.randint(1, 100) for _ in range(n)]

print("Original array:")
display(arr)

start_time = time.time()
merge_sort(arr, 0, n - 1)
end_time = time.time()

print("Sorted array:")
display(arr)

print(f"Time taken to sort: {end_time - start_time:.6f} seconds")
