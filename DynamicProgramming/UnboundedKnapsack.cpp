int unKnapsack(int w[],int v[],int n,int c){
  int dp[n+1][c+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=c;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
      else if(w[i-1]>j){
        dp[i][j]=dp[i-1][j];
      }
      else{
        dp[i][j]=max(val[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
      }
    }
  }
  return dp[n][c];
}
