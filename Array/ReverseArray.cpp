void reverse(int *a, int n){
  int start=0.end=n-1;
  while(s<e){
    int temp=a[start];
    a[start]=a[end];
    a[end]=temp;
    start++;
    end--;
  }
}

//Recursively
void reverse(int *a,int n){
  int start=0.end=n-1;
  if(start>=end){
    return;
  }
  int temp=a[start];
  a[start]=a[end];
  a[end]=temp;
  return reverse(a+1,n-1);
}
