//top-down dp - O(n*t) time
int mcc(int n,int coins[],int t,int dp[]){
  if(n==0){
    return 0;
  }
  if(dp[n]!=0){
    return 0;
  }
  int ans=INT_MAX;
  for(int i=0;i<t;i++){
    if(n-coins[i]>=0){
      int d=mcc(n-coins[i],coins,t,dp);
      ans=min(ans,d)+1;
    }
    else{
      break;
    }
  }
  dp[n]=ans;
  return dp[n];
}

//bottom-up dp - O(n*t) time
int mcc1(int n,int coins[],int t){
  if(n==0){
    return 0;
  }
  int dp[1000];//assuming n<1000
  for(int i=1;i<n;i++){
    dp[i]=INT_MAX;
    for(int j=0;j<t;j++){
      if(n-coins[j]>=0){
        int d=dp[n-coins[j]];
        dp[i]=min(d,dp[i])+1;
      }
      else{
        break;
      }
    }
  }
  return dp[n];
}
