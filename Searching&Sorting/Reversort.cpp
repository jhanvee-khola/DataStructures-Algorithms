//Repeatedly find the index of the minimum element from i to n, say j, and then reverse the subarray from i to j

void reverSort(int a[],int n){
  for(int i=0;i<n-1;i++){
    int mini=a[i],j=i;
    for(int k=i;k<n;k++){
      if(a[k]<mini){
        mini=a[k];
        j=k;
      }
    }
    int m=j-i+1;
    for(int k=i;k<=(i+j)/2;k++){
      swap(a[k],a[m-k]);
    }
  }
}
