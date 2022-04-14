//Given an array of available denomination of coins, find the minimum no. of coins required to make the given sum of money

//recursive approach
int mcc(int n,int a[],int k){
  if(n==1){
    if(k%a[0]==0){
      return k/a[0];
    }
    return 1e9;
  }
  int nt=mcc(n-1,a,k);
  int t=INT_MAX;
  if(a[n-1]<=k){
    t=1+mcc(n,a,k-a[n-1]);
  }
  return min(t,nt);
}

//top-dpwn dp
int mcc(vector<int>& a,int n,int k,vector<vector<int>> dp){
    if(n==1){
        if(k%a[0]==0){
            return k/a[0];
        }
        return 1e9;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int nt=mcc(a,n-1,k,dp);
    int t=INT_MAX;
    if(a[n-1]<=k){
        t=1+mcc(a,n,k-a[n-1],dp);
    }
    return dp[n][k]=min(t,nt);
}

//bottom-up dp
int mcc(vector<int>& a, int k) {
    int n=a.size();
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=k;i++){
        if(i%a[0]==0){
            dp[1][i]=i/a[0];
        }
        else{
            dp[1][i]=1e9;
        }
    }
    for(int i=1;i<=k;i++){
        dp[0][i]=-1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            int nt=dp[i-1][j];
            int t=INT_MAX;
            if(a[i-1]<=j){
                t=1+dp[i][j-a[i-1]];
            }
            dp[i][j]=min(t,nt);
        }
    }
    if(dp[n][k]>=1e9){
        dp[n][k]=-1;
    }
    return dp[n][k];
}
