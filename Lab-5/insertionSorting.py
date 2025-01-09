import time

def insertionSorting(arr,n):
  for i in range (n):
    j=i-1
    temp = arr[i]
    while j>=0 and temp < arr[j]:
      arr[j+1] = arr[j]
      j=j-1
    arr[j+1] = temp
  return arr

arr = [22,67,32,45,12,107,678,4,66]
startTime = time.time()
n=len(arr)
sortedArray=insertionSorting(arr,n)
endTime = time.time()
print ("Sorted array is:", sortedArray)
print ("Time taken to sort the array is: ", endTime-startTime)