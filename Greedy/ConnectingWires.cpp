int connectWires(int w[],int b[],int n){
  sort(w,w+n);
  sort(b,b+n);
  int ans=0;
  for(int i=0;i<n;i++){
    ans+=abs(w[i]-b[i]);
  }
  return ans;
}
