//Given a height h, count the maximum number of balanced binary trees possible with height h

#define mod 1000000007

//recursive approach
long long bbtCounter(int h){
  if(h==0||h==1){
    return 1;
  }
  return bbtCounter(h-1)*bbtCounter(h-1) + bbtCounter(h-1)*bbtCounter(h-2) + bbtCounter(h-2)*bbtCounter(h-1);
}

//bottom-up dp
long long bbtCounter(int h){
  long long dp[h+1];
  dp[0]=dp[1]=1;
  for(int i=2;i<=h;i++){
    //dp[i]=dp[i-1]*dp[i-1]+dp[i-2]*dp[i-1]+dp[i-1]*dp[i-2];
    dp[i]=(dp[i-1]*((2*dp[i-2])%mod)+dp[i-1])%mod)%mod;
  }
  return dp[h];
}

//memory optimization using just 2 variables instead of complete array
