//Maximum sum of the subsequence such that no two adjacent elements are present in the chosen subsequence

//recursive approach
int mnas(int a[],int n){
  if(n==0){
    return 0;
  }
  if(n==1){
    return a[0];
  }
  return max(mnas(a,n-1),a[n-1]+mnas(a,n-2));
}

//top-down dp
int mnas(int a[],int n,int dp[]){
   if(n==0){
    return 0;
  }
  if(n==1){
    return dp[1]=a[0];
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  return dp[n]=max(mnas(a,n-1),a[n-1]+mnas(a,n-2));
}

//bottom-up dp
int mnas(int a[],int n){
  int dp[n+1];
  dp[0]=0;
  dp[1]=a[0];
  for(int i=2;i<=n;i++){
    dp[i]=max(dp[i-1],a[i]+dp[i-2]);
  }
  return dp[n-1];
}

//space-optimization
int mnas(int a[],int n){
  int a=0,b=a[0];
  for(int i=2;i<=n;i++){
    int c=max(b,a[i]+a);
    a=b;
    b=c;
  }
  return b;
}
