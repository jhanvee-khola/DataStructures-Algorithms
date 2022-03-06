//recursive
int knapsack(int w[],int v[],int n,int c){
  if(n==0 || c==0){
    return 0;
  }
  if(w[n-1]>c){
    return knapsack(w,v,n-1,c);
  }
  else{
    return max(v[n-1]+knapsack(w,v,n-1,c-w[n-1]),knapsack(w,v,n-1,c));
  }
}

//top-down dp
//initialize all values in dp[][] with -1;
int knapsack1(int w[],int v[],int n,int c,int dp[n+1][c+1]){
  if(n==0 || c==0){
    return 0;
  }
  if(dp[n][c]!=-1){
    return dp[n][c];
  }
  else{
    if(w[n-1]>c){
      return dp[n][c]=knapsack1(w,v,n-1,c);
    }
    else{
      return dp[n][c]=max(v[n-1]+knapsack1(w,v,n-1,c-w[n-1]),knapsack1(w,v,n-1,c));
    }
  }
}

//bottom-up dp
int knapsack2(int w[],int v[],int n,int c){
  int dp[n+1][c+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=c;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
      else if(w[i-1]>c){
        dp[i][j]=dp[i-1][j];
      }
      else{
        dp[i][j]=max(val[i-1]+dp[i-1][c-w[i-1]],dp[i-1][j]);
      }
    }
  }
  return dp[n][c];
}
