import random
import time
def QuickSort(arr, l, r):
    if l < r:
        p = randomizedPartition(arr, l, r)  
        QuickSort(arr, l, p - 1)   
        QuickSort(arr, p + 1, r)   

def Partition(arr, l, r):
    pivot = arr[l]   
    x = l            
    y = r            
    while x < y:
        while arr[x] <= pivot and x <= r:
            x += 1
        while arr[y] > pivot and y >= l:
            y -= 1
        if x < y:
           arr[x],arr[y]=arr[y],arr[x]
    arr[l],arr[y]=arr[y],arr[l]
    return y  

def randomizedPartition(arr,l,r):
   i = random.randint(l,r)
   arr[i],arr[r]=arr[r],arr[i]
   return Partition(arr,l,r)

arr = [22,67,32,45,12,107,678,4,66]
startTime = time.time()
QuickSort(arr, 0, len(arr) - 1)
endTime = time.time()
print ("Sorted array is:", arr)
print ("Time taken to sort the array is: ", endTime-startTime)