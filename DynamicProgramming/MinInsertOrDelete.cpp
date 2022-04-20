//Given 2 non-empty strings s1 and s2, calculate the minimum no. of operations(insertion or deletion) to convert string s1 into string s2

int lcs(string s1,string s2){
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
    return dp[n][m];
}
int minID(string s1,string s2){
  int n=s1.length(),m=s2.length();
  int l=lcs(s1,s2);
  return (n-l)+(m-l);
}
