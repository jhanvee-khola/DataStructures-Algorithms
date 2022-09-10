//Recursive approach
int minOperations(int dimensions[],int i,int j){
  if(i==j){
    return 0;
  }
  int mini=1e9;
  for(int k=i;k<j;k++){
    int steps=dimensions[i-1]*dimensions[k]*dimensions[j] + minOperations(dimensions,i,k) + minOperations(dimensions,k+1,j);
    mini=min(mini,steps);
  }
  return mini;
}

int matrixMultiply(int dimensions[],int n){
  return minOperations(dimensions,1,n-1);
}

//Top-down DP
int minOperations(int dimensions[],int i,int j,vector<vector<int>> &dp){
  if(i==j){
    return 0;
  }
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
  int mini=1e9;
  for(int k=i;k<j;k++){
    int steps=dimensions[i-1]*dimensions[k]*dimensions[j] + minOperations(dimensions,i,k,dp) + minOperations(dimensions,k+1,j,dp);
    mini=min(mini,steps);
  }
  return dp[i][j]=mini;
}
int matrixMultiply(int dimensions[],int n){
  vector<vector<int>> dp(n,vector<int>(n,-1));
  return minOperations(dimensions,1,n-1);
}

//Bottom-up DP
int matrixMultiply(int dimensions[],int n){
  vector<vector<int>> dp(n,vector<int>(n,0));
  for(int i=n-1;i>=1;i--){
    for(int j=i+1;j<=n-1;j++){
      int mini=1e9;
      for(int k=i;k<j;k++){
        int steps=dimensions[i-1]*dimensions[k]*dimensions[j] + dp[i][k] + dp[k+1][j];
        mini=min(mini,steps);
      }
      dp[i][j]=mini;
    }
  }
  return dp[1][n-1];
}
