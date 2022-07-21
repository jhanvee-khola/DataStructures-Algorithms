//Recursive
int solve(vector<int> p,int n,int fee,int i,int buy){
    if(i==n){
        return 0;
    }
    if(buy){
        int b=-p[i]+solve(p,n,fee,i+1,0);
        int nb=solve(p,n,fee,i+1,1);
        return max(b,nb);
    }
    int s=p[i]-fee+solve(p,n,fee,i+1,1);
    int ns=solve(p,n,fee,i+1,0);
    return max(s,ns);
}
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    return solve(prices,n,fee,0,1);
}

//Top-down DP
int dp[50001][2];
int solve(vector<int> p,int n,int fee,int i,int buy){
    if(i==n){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
        int b=-p[i]+solve(p,n,fee,i+1,0);
        int nb=solve(p,n,fee,i+1,1);
        return dp[i][buy]=max(b,nb);
    }
    int s=p[i]-fee+solve(p,n,fee,i+1,1);
    int ns=solve(p,n,fee,i+1,0);
    return dp[i][buy]=max(s,ns);
}
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    memset(dp,-1,sizeof(dp));
    return solve(prices,n,fee,0,1);
}

//Bottom-up DP
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy){
                int b=-prices[i]+dp[i+1][0];
                int nb=dp[i+1][1];
                dp[i][buy]=max(b,nb);
            }
            else{
                int s=prices[i]-fee+dp[i+1][1];
                int ns=dp[i+1][0];
                dp[i][buy]=max(s,ns);
            }
        }
    }
    return dp[0][1];
}

//Space-optimization
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    int afterB,afterNB,currB,currNB;
    afterB=afterNB=0;
    for(int i=n-1;i>=0;i--){
        int b=-prices[i]+afterNB;
        int nb=afterB;
        currB=max(b,nb);

        int s=prices[i]-fee+afterB;
        int ns=afterNB;
        currNB=max(s,ns);

        afterB=currB;
        afterNB=currNB;
    }
    return afterB;
}
