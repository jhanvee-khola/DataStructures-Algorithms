//Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum

//recursive solution
int minRec(int a[],int n,int temp,int total){
  if(n==0){
    return abs((total-temp)-temp);
  }
  return min(minRec(a,n-1,temp,total),minRec(a,n-1,temp+a[n-1],total));
}
int minDiff(int a[],int n){
  int total=0;
  for(int i=0;i<n;i++){
    total+=a[i];
  }
  return minRec(a,n,0,total);
}

//bottom-up dp
int minimumDifference(vector<int>& a) {
    int total=0,n=a.size();
    for(int i=0;i<n;i++){
        total+=a[i];
    }
    bool dp[n+1][total+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=total;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=total;j++){
            if(a[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<=sum/2;i--){
        if(dp[n][i]){
            ans=total-2*i;
            break;
        }
    }
    return ans;
}
