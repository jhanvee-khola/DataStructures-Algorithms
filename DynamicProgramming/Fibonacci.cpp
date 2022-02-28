//normal recursion - O(2^n) time
int fib(int n){
  if(n==0 || n==1){
    return n;
  }
  return fib(n-1)+fib(n-2);
}

//top-down dp - O(n) time, O(n) space
//recursion+memoisation
int fib1(int n,int dp[]){
  if(n==0 || n==1){
    return n;
  }
  if(dp[n]!=0){
    return dp[n];
  }
  int ans=fib1(n-1)+fib(n-2);
  return dp[n]=ans;
}

//bottom-up dp - O(n) time, O(n) space
int fib2(int n){
  int dp[100]={0};//assuming n<100
  dp[1]=1;
  for(int i=2;i<=n;i++){
    dp[i]=d[i-1]+dp[i-2];
  }
  return dp[n];
}

//bottom-up optimised - O(n) time, O(1) space
int fib3(int n){
  if(n==0 || n==1){
    return n;
  }
  int a=0,b=1,c;
  for(int i=2;i<=n;i++){
    c=a+b;
    a=b;
    b=c;
  }
  return c;
}

//Matrix-exponentiation approach - O(logn) time
int fib4(int n){

}
