void insertionSort(int *a,int n){
  for(int i=1;i<n;i++){
    int t=a[i];
    int j=i-1;
    while(j>=0 && a[j]>t){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=t;
  }
}
