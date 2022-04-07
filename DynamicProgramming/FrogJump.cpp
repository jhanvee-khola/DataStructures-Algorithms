//Recursive Approach
int frogJump(int a[],int n){
  if(n==0){
    return n;
  }
  int l=frogJump(a,n-1)+abs(a[n]-a[n-1]);
  int r=INT_MAX;
  if(n>=1){
    frogJump(a,n-2)+abs(a[n]-a[n-2]);
  }
  return min(l,r);
}

//top-down dp
int frogJump(int a[],int n,int dp[]){
  if(n==0){
    return n;
  }
  if(dp[n]!=-1){
    retuen dp[n];
  }
  int l=frogJump(a,n-1)+abs(a[n]-a[n-1]);
  int r=INT_MAX;
  if(n>=1){
    frogJump(a,n-2)+abs(a[n]-a[n-2]);
  }
  return dp[n]=min(l,r);
}

//bottom-up dp
int frogJump(int a[],int n){
  int dp[n];
  dp[0]=0;
  dp[1]=abs(a[1]-a[0]);
  for(int i=2;i<n;i++){
    int l=dp[i-1]+abs(a[i]-a[i-1]);
    int r=dp[i-2]+abs(a[i]-a[i-2]);
    dp[i]=min(l,r);
  }
  return dp[n-1]
}

//space-optimised dp
int frogJump(int a[],int n){
  int a=0,b=abs(a[1]-a[0]);
  for(int i=2;i<n;i++){
    int l=a+abs(a[i]-a[i-2]);
    int r=b+abs(a[i]-a[i-1]);
    dp[i]=min(l,r);
    a=b;
    b=dp[i];
  }
  return dp[n-1]
}

//follow-up question: If frog can take 1,2,....k steps at a time, find the solution
//recursive solution
int frogJump(int a[],int n,int k){
  if(n==0){
    return 0;
  }
  int ans=INT_MAX;
  for(int i=1;i<=k;i++){
    int e=frogJump(a,n-j)+abs(a[n]-a[n-j]);
    ans=min(ans,e);
  }
  return ans;
}

//bottom-up dp;
int frogJump(int a[],int n,int k){
  int dp[n];
  dp[0]=0;
  for(i=1;i<n;i++){
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++){
      if(i-j>=0){
        int e=dp[i-j]+abs(a[i]-a[i-j]);
        minSteps=min(minSteps,e);
      }
    }
    dp[i]=minSteps;
  }
  return dp[n-1];
}
