//Given an array of non-negative integers, determine the no. ways in which the array can be partitioned such that the difference of the 2 subsets formed is equal to the given differnce k

int pwgd(int a[],int n,int k){
  int total=0;
  for(int i=0;i<n;i++){
    total+=a[i];
  }
  //s1+s2=total
  //and s1-s2=k
  //solving the 2 equations, we get a fixed value for s1(sum of 1st subset) and hence the problem is reduced to count the no. of subsets with given sum
  int dp[n+1][total+1];
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<=n;i++){
    dp[i][0]=1;
  }
  for(int i=1;i<=total;i++){
    dp[0][i]=0;
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<=total;j++){
      if(a[i-1]>j){
        dp[i][j]=dp[i-1][j];
      }
      else{
        dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
      }
    }
  }
  int s1sum=(total+k)/2;
  return dp[n][s1sum];
}
