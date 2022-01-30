void selectionSort(int *a,int n){
  int min_idx=a[0],j=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(a[j]<a[min_idx]){
        min_idx=j;
      }
    }
    swap(a[min_idx],a[i]);
  }
}
