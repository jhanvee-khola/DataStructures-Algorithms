int rodCut(int r[],int n,p[],int l){
  //in this case specific array r is given of the available choices for pieces' length
  //if not given then => all length pieces can be made => int dp[l+1][l+1]
  int dp[n+1][l+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=l;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
      else if(r[i-1]>j){
        dp[i][j]=dp[i-1][j];
      }
      else{
        dp[i][j]=max(p[i-1]+dp[i][j-p[i-1]],dp[i-1][j]);
      }
    }
  }
  return dp[n][l];
}
