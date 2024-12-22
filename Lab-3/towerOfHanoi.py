def towerOfHanoi(n,src,dst,temp):
  if(n==1):
    print(f"Move disk {n} from {src} to {dst}")
    return
  else:
    towerOfHanoi(n-1,src,temp,dst)
    print(f"Move disk {n} from {src} to {dst}")
    towerOfHanoi(n-1,temp,dst,src)
    return
  
towerOfHanoi(3,'A','C','B')
