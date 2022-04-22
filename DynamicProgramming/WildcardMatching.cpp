//recursive approach
bool isMatch(string s,string t,int n,int m){
  if(n==0 && m==0){
    return true;
  }
  else if(m==0 && n>0){
    return false;
  }
  else{
    for(int i=m-1;i>=0;i--){
      if(t[i]!='*'){
        return false;
      }
    }
    return true;
  }
  if(s[n-1]==t[m-1] || t[m-1]=='?'){
    return isMatch(s,t,n-1,m-1);
  }
  if(t[m-1]=='*'){
    isMatch(s,t,n,m-1)||isMatch(s,t,n-1,m);
  }
  return false;
}

//top-down dp
bool isMatch(string s,string t,int n,int m,int dp[][]){
  if(n==0 && m==0){
    return true;
  }
  else if(m==0 && n>0){
    return false;
  }
  else{
    for(int i=m-1;i>=0;i--){
      if(t[i]!='*'){
        return false;
      }
    }
    return true;
  }
  if(dp[n][m]!=-1){
    return dp[n][m];
  }
  if(s[n-1]==t[m-1] || t[m-1]=='?'){
    return dp[n][m]=isMatch(s,t,n-1,m-1);
  }
  if(t[m-1]=='*'){
    dp[n][m]=isMatch(s,t,n,m-1)||isMatch(s,t,n-1,m);
  }
  return dp[n][m]=false;
}

//bottom-up dp
bool isMatch(string s,string t){
  int n=s.length(),m=t.length();
  bool dp[n+1][m+1];
  memset(dp,true,,sizeof(dp));
  dp[0][0]=true;
  for(int i=1;i<=n;i++){
    dp[i][0]=false;
  }
  for(int i=1;i<=m;i++){
    for(int j=0;j<i;j++){
      if(t[j]!='*'){
        dp[0][i]=false;
        break;
      }
    }
    if(b){
      dp[i][j]=true;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s[i-1]==t[j-1] || t[j-1]=='?'){
        dp[i][j]=dp[i-1][j-1];
      }
      else if(t[j-1]=='*'){
        dp[i][j]=dp[i][j-1]||dp[i-1][j];
      }
      else{
        dp[i][j]=false;
      }
    }
  }
  return dp[n][m];
}  
