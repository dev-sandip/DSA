def left(i):
    
    return 2 * i + 1

def right(i):
    return 2 * i + 2

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def MaxHeapify(arr, i, n):
    l = left(i)
    r = right(i)
    largest = i
    
    if l < n and arr[l] > arr[largest]:
        largest = l
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        swap(arr, i, largest)
        MaxHeapify(arr, largest, n)

def BuildMaxHeap(arr, n):
    for i in range(n // 2 - 1, -1, -1):
        MaxHeapify(arr, i, n)

def heapSort(arr, n):
    BuildMaxHeap(arr, n)
    for i in range(n - 1, 0, -1):
        swap(arr, 0, i)
        MaxHeapify(arr, 0, i)
    return arr

import time
arr = [22, 67, 32, 45, 12, 107, 678, 4, 66]
startTime = time.time()
n = len(arr)
sortedArray = heapSort(arr, n)
endTime = time.time()

print("Sorted array is:", sortedArray)
print("Time taken to sort the array is:", endTime - startTime)
