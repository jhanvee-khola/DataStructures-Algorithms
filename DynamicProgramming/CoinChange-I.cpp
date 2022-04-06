//count total no. ways in which you can pay a sum of money using the given denomination of coins

int maxWaysOfCoinChange(int d[],int n,int k){
  int dp[n+1][k+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=k;j++){
      if(i==0){
        dp[i][j]=0;
      }
      else if(j==0){
        dp[i][j]=1;
      }
      else if(d[i-1]>j){
        dp[i][j]=dp[i-1][j];
      }
      else{
        dp[i][j]=dp[i-1][j]+dp[i][j-d[i-1]];
      }
    }
  }
  return dp[n][k];
}
