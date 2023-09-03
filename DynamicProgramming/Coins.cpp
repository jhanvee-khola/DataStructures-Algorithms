//Let N be a positive odd number. There are N coins, numbered 1,2,…,N. 
//For each i (1≤i≤N), when Coin i is tossed, it comes up heads with probability pi and tails with probability 1−pi.
// Taro has tossed all the N coins. Find the probability of having more heads than tails.

double help(vector<double> p,int i,int headsReq,vector<vector<double>> &dp){
  if(headsReq==0){
    return 1;
  }
  if(i==p.size()){
    return 0;
  }
  if(dp[i][headsReq]>-0.9){
    return dp[i][headsReq];
  }
  double op1=p[i]*help(p,i+1,headsReq-1,dp);
  double op2=(1-p[i])*help(p,i+1,headsReq,dp);
  return dp[i][headsReq]=op1+op2;
}
int main(){
  int n;
  cin>>n;
  vector<double> p(n);
  for(int i=0;i<n;i++){
    cin>>p[i];
  }
  vector<vector<double>> dp(n,vector<double>(n,-1));
  cout<<help(p,0,(n+1)/2,dp);
}
