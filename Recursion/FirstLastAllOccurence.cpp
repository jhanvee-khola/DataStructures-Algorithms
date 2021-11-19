int firstOccur(int *a,int n,int key){
  if(n==0){
    return -1;
  }
  if(a[0]==key){
    return 0;
  }
  int i=firstOccur(a+1,n-1,key);
  if(i==-1){
    return -1;
  }
  return i+1;//to get the correct index with respect to the total array
}

int lastOccur(int *a,int n, int key){
  if(n==0){
    return -1;
  }
  int i=lastOccur(a+1,n-1,key);
  if(i==-1){
    if(a[0]==key){
      return 0;
    }
    else{
      return -1;
    }
  }
  return i+1;
}

void allOccur(int *a,int n,int key){
  
}
