int pwgd(int a[],int n,int k){
  int total=0;
  for(int i=0;i<n;i++){
    total+=a[i];
  }
  bool dp[n+1][total+1];
  for(int i=0;i<=n;i++){
    dp[i][0]=true;
  }
  for(int i=1;i<=total;i++){
    dp[0][i]=false;
  }
  for(int i=0;i<n;i++){
  
  }
}
