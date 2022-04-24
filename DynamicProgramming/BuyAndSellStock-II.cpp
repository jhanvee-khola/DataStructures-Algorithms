//recursive approach
int buySellStock(int p[],int n,bool buy){
  if(n==0){
    return 0;
  }
  if(buy){
    int b=-p[0]+buySellStock(p+1,n-1,false);
    int nb=buySellStock(p+1,n-1,true);
    return max(b,nb);
  }
  int s=p[0]+buySellStock(p+1,n-1,true);
  int ns=buySellStock(p+1,n-1,false);
  return max(s,ns);
}
