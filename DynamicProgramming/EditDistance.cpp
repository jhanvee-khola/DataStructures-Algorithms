//Given two strings s and t, return the minimum number of operations(insert, delete, replace) required to convert s to t

//recursive approach
int minDistance(string s,string t,int n,int m){
  if(m==0){
    return n;//n deletions
  }
  if(n==0){
    return m;//m insertions
  }
  
  if(s[n-1]==t[m-1]){
    return minDistance(s,t,n-1,m-1);
  }
  int op1=1+minDistance(s,t,n,m-1);//insert
  int op2=minDistance(s,t,n-1,m);//delete
  int op3=minDistance(s,t,n-1,m-1);//replace
  return min(op1,min(op2,op3));
}

//top-down dp
int minDistance(string s,string t,int n,int m,int dp[][]){
  if(m==0){
    return n;//n deletions
  }
  if(n==0){
    return m;//m insertions
  }
  if(dp[n][m]!=-1){
    return dp[n][m];
  }
  if(s[n-1]==t[m-1]){
    return dp[n][m]=minDistance(s,t,n-1,m-1);
  }
  int op1=1+minDistance(s,t,n,m-1);//insert
  int op2=1+minDistance(s,t,n-1,m);//delete
  int op3=1+minDistance(s,t,n-1,m-1);//replace
  return dp[n][m]=min(op1,min(op2,op3));
}

//bottom-up dp
int minDistance(string s,string t){
  int n=s.length(),m=t.length();
  int dp[n+1][m+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i==0){
        dp[i][j]=j;
      }
      else if(j==0){
        dp[i][j]=i;
      }
      else{
        if(s[i-1]==t[j-1]){
          dp[i][j]=dp[i-1][j-1];
        }
        else{
          int op1=1+dp[i][j-1];//insert
          int op2=1+dp[i-1][j];//delete
          int op3=1+dp[i-1][j-1];//replace
          dp[i][j]=min(op1,min(op2,op3));
        }
      }
    }
  }
  return dp[n][m];
}
