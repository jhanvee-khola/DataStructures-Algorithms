//Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X

//bottom-up dp
//This method is valid only for those arrays which contains positive elements
int countSubsets(int a[],int n,int k){
  int dp[n+1][k+1];
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<=n;i++){
      dp[i][0]=1;
  }
  for(int i=1;i<=k;i++){
      dp[0][i]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(a[i-1]>j){
        dp[i][j]=dp[i-1][j];
      }
      else{
        dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
      }
    }
  }
  return dp[n][k];
}
