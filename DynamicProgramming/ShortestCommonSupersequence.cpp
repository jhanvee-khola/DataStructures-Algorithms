//Given two strings, return the shortest string that has both the given strings as subsequences

string scs(string s1,string s2){
  //length of the scs would s1.length+s2.length-lcs.length (intersection formula)
  //calculating length of lcs and dp matrix
  int n=s1.length(),m=s2.length();
  int dp[n+1][m+1];
  for(int i=0;i<=n;i++){
      for(int j=0;j<=m;j++){
          if(i==0 || j==0){
          dp[i][j]=0;
          }
          else{
              if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
              }
              else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
      }
  }
  int l=dp[n][m];
  int i=n,j=m;
  string ans="";
  while(i>0 && j>0){
      if(s1[i-1]==s2[j-1]){
          ans+=s1[i-1];
          i--;
          j--;
      }
      else{
          if(dp[i-1][j]>dp[i][j-1]){
              ans+=s1[i-1];
              i--;
          }
          else{
              ans+=s2[j-1];
              j--;
          }
      }
  }
  while(i>0){
      ans+=s1[i-1];
      i--;
  }
  while(j>0){
      ans+=s2[j-1];
      j--;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
