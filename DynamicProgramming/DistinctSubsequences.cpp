//recursive approach
int numDistinct(string s,string t,int n,int m){
  if(m==0){
    return 0;
  }
  if(n==0){
    return 1;
  }
  if(s[n-1]==t[m-1]){
    return numDistinct(s,t,n-1,m-1)+numDistinct(s,t,n-1,m);
  }
  return numDistinct(s,t,n-1,m);
}

//top-down dp
int numDistinct(string s,string t,int n,int m,int dp[][]){
  if(m==0){
    return 0;
  }
  if(n==0){
    return 1;
  }
  if(dp[n][m]!=-1){
    return dp[n][m];
  }
  if(s[n-1]==t[m-1]){
    return dp[n][m]=numDistinct(s,t,n-1,m-1)+numDistinct(s,t,n-1,m);
  }
  return dp[n][m]=numDistinct(s,t,n-1,m);
}

//bottom-up dp
int numDistinct(string s,string t){
  int n=s.length(),m=t.length();
  int dp[n+1][m+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i==0){
        dp[i][j]=0;
      }
      if(j==0){
        dp[i][j]=1;
      }
      if(s[i-1]==t[j-1]){
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][m];
}

//space-optimization
int numDistinct(string s,string t){
  int n=s.length(),m=t.length();
  
}
