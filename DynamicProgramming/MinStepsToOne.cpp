#include<bits/stdc++.h>

//top-down dp - O(n) time
int msto(int n,int dp[]){
  int op1,op2,op3;
  op1=op2=op3=INT_MAX;
  if(dp[n]!=0){
    return dp[n];
  }
  if(n%3==0){
    op1=msto(n/3,dp)+1;
  }
  if(n%2==0){
    op2=msto(n/2,dp)+1;
  }
  op3=msto(n-1,dp)+1;
  int ans=min(min(op1,op2),op3);
  return dp[n]=ans;
}

//bottom-up dp - O(n) time
int msto1(int n){
  int dp[1000]={0};//assuming n<1000
  for(int i=2;i<=n;i++){
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(i%3==0){
      op1=dp[i/3];
    }
    if(i%2==0){
      op2=dp[i/2];
    }
    op3=dp[i-1];
    dp[i]=min(min(op1,op2),op3)+1;
  }
  return dp[n];
}

