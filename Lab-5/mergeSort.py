
# need to be fixed

import time
def mergeSort(arr,l,r):
  if l<r:
    m=((l+r)//2)
    mergeSort(arr,l,m)
    mergeSort(arr,m+1,r)
    Merge(arr,l,m+1,r)


def Merge(arr,l,m,r):
  i=l
  j=m
  k=l
  arrB=[]
  while(i<m and j<=r):
    if arr[i]<arr[j]:
      arrB[k]=arr[i]
      i += 1
      k += 1
    else:
      arrB[k]=arr[j]
      j += 1
      k += 1
  for x in range(i,m):
    arrB[k]=arr[x]
    k += 1
  for x in range(j,r+1):
    arrB[k]=arr[x]
    k += 1
    j += 1
  for x in range(k,r+1):
    arr[x]=arrB[x]
  return arr

arr = [22,67,32,45,12]
startTime = time.time()
n=len(arr)
mergeSort(arr,0,n-1)
endTime = time.time()
print ("Sorted array is:", arr)
print ("Time taken to sort the array is: ", endTime-startTime)