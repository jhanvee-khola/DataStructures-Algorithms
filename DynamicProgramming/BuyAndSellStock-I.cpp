int buySellStock(int p[],int n){
  int mini=p[0],ans=0;
  for(int i=1;i<n;i++){
    int profit=a[i]-mini;
    ans=max(ans,profit);
    mini=min(mini,a[i]);
  }
  return ans;
}
