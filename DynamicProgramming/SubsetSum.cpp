//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum

//recursive
bool subsetSum(int a[],int n,int k){
  if(k==0){
    return true;
  } 
  if(n==0){
    return false;
  }
  if(a[n-1]>k){
    return subsetSum(a,n-1,k);
  }
  else{
    return subsetSum(a,n-1,k) || subsetSum(a,n-1,k-a[n-1]);
  }
}

//top-down dp
//initialize all values in dp[][] with -1;
int subsetSum1(int a[],int n,int k,int dp[n+1][k+1]){
  if(k==0){
    return 1;
  } 
  if(n==0){
    return 0;
  }
  if(dp[n][k]!=-1){
    return dp[n][k];
  }
  if(a[n-1]>k){
    return dp[n][k]=subsetSum(a,n-1,k);
  }
  else{
    return dp[n][k]=subsetSum(a,n-1,k) || subsetSum(a,n-1,k-a[n-1]);
  }
}

//bottom-up dp 
int subsetSum2(int a[],int n,int k){
  bool dp[n+1][k+1];
  for(int i=0;i<=n;i++){
    dp[i][0]=true;
  }
  for(int i=1;i<=k;i++){
    dp[0][i]=false;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(a[i-1]>j){
        dp[i][j]=dp[i-1][j];
      }
      else{
        dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
      }
    }
  }
  return dp[n][k];
}
