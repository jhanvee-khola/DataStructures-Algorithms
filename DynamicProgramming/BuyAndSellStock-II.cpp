//recursive approach
int buySellStock(int p[],int n,int i,int buy){
  if(i==n){
    return 0;
  }
  if(buy){
    int b=-p[i]+buySellStock(p,n,i+1,0);
    int nb=buySellStock(p,n,i+1,1);
    return max(b,nb);
  }
  int s=p[i]+buySellStock(p,n,i+1,1);
  int ns=buySellStock(p,n,i+1,0);
  return max(s,ns);
}

//top-down dp
int buySellStock(int p[],int n,int i,int buy,int dp[][2]){
  if(i==n){
    return 0;
  }
  if(dp[i][buy]!=-1){
    return dp[i][buy];
  }
  if(buy){
    int b=-p[i]+buySellStock(p,n,i+1,0,dp);
    int nb=buySellStock(p,n,i+1,1,dp);
    return dp[i][buy]=max(b,nb);
  }
  int s=p[i]+buySellStock(p,n,i+1,1,dp);
  int ns=buySellStock(p,n,i+1,0,dp);
  return dp[i][buy]=max(s,ns);
}

//bottom-up dp
int buySellStock(int p[],int n){
  int dp[n+1][2];
  dp[n][0]=dp[n][1]=0;
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<2;j++){
      if(j){
        int b=-p[i]+dp[i+1][0];
        int nb=dp[i+1][1];
        dp[i][j]=max(b,nb);
      }
      else{
        int s=p[i]+dp[i+1][1];
        int ns=dp[i+1][0];
        dp[i][j]=max(s,ns);
      }
    }
  }
  return dp[0][1];
}

//space-optimization
int buySellStock(int p[],int n){
  int prev[2],curr[2];
  prev[0]=prev[1]=0;
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<2;j++){
      if(j){
        int b=-p[i]+prev[0];
        int nb=prev[1];
        curr[j]=max(b,nb);
      }
      else{
        int s=p[i]+prev[1];
        int ns=prev[0];
        curr[j]=max(s,ns);
      }
    }
    prev=curr;
  }
  return prev[1];
}
