//dp solution - O(n^2) solution
bool canJump(vector<int>& nums) {
    int n=nums.size();
    bool dp[n+1];
    dp[0]=dp[1]=true;
    for(int i=2;i<=n;i++){
        bool b=false;
        for(int j=i-1;j>=1;j--){
            if(nums[j-1]>=i-j && dp[j]){
                b=true;
                break;
            }
        }
        dp[i]=b;
    }
    return dp[n];
}

//greedy solution
bool canJump(vector<int>& nums) {
    int target=nums.size()-1;
    for(int i=nums.size()-1;i>=0;i--){
        if(i+nums[i]>=target){
            target=i;
        }
    }
    return target==0;
}
