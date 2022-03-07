//whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same

//bottom-up dp
bool subsetSum(vector<int>& nums,int k){
    int n=nums.size();
    bool dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=k;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(nums[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[n][k];
}
bool canPartition(vector<int>& nums) {
    int total=0;
    for(int i=0;i<nums.size();i++){
        total+=nums[i];
    }
    if(total%2!=0){
        return false;
    }
    return subsetSum(nums,total/2);
}
