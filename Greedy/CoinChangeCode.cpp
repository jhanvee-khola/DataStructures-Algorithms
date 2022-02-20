int minCoin(int amt,int n,int* coins){
  int ans=0;
  while(amt>0){
    int i=upper_bound(coins,coins+n,amt)-1-coins;
    amt-=coins[i];
    ans++;
  }
  return ans;
}
