//total no. of distinct ways to reach nth step from 0th step if you can take 1 aur 2 steps at a time

//recursion solution
int climbStairs(int n){
  if(n==0 || n==1){
    return 1;
  }
  return climbStairs(n-1)+climbStairs(n-2);
}

//bottom-up dp
int climbstairs1(int n){
  int a[n+1];
  a[0]=a[1]=1;
  for(int i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
  }
  return a[n];
}

//space optimization
int climbStairs2(int n){
  int a=1,b=1;
  for(int i=2;i<=n;i++){
    int c=a+b;
    a=b;
    b=c;
  }
  return b;
}
