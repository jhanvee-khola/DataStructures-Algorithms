//Recursive
int solve(vector<int> p,int n,int i,int buy,int cap){
    if(i==n || cap==0){
        return 0;
    }
    if(buy){
        int b=-p[i]+solve(p,n,i+1,0,cap);
        int nb=solve(p,n,i+1,1,cap);
        return max(b,nb);
    }
    int s=p[i]+solve(p,n,i+1,1,cap-1);
    int ns=solve(p,n,i+1,0,cap);
    return max(s,ns);
}
int maxProfit(vector<int>& prices,int k) {
    int n=prices.size();
    return solve(prices,n,0,1,k);
}

//Top-down dp
int dp[1001][2][101];
int solve(vector<int> p,int n,int i,int buy,int cap){
    if(i==n || cap==0){
        return 0;
    }
    if(dp[i][buy][cap]!=-1){
        return dp[i][buy][cap];
    }
    if(buy){
        int b=-p[i]+solve(p,n,i+1,0,cap);
        int nb=solve(p,n,i+1,1,cap);
        return dp[i][buy][cap]=max(b,nb);
    }
    int s=p[i]+solve(p,n,i+1,1,cap-1);
    int ns=solve(p,n,i+1,0,cap);
    return dp[i][buy][cap]=max(s,ns);
}
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    memset(dp,-1,sizeof(dp));
    return solve(prices,n,0,1,k);
}

//Bottom-up dp
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=k;cap++){
                if(buy){
                    int b=-prices[i]+dp[i+1][0][cap];
                    int nb=dp[i+1][1][cap];
                    dp[i][buy][cap]=max(b,nb);
                }
                else{
                    int s=prices[i]+dp[i+1][1][cap-1];
                    int ns=dp[i+1][0][cap];
                    dp[i][buy][cap]=max(s,ns);
                }
            }
        }
    }
    return dp[0][1][k];
}

//Space-optimization
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> after(2,vector<int>(k+1,0));
    vector<vector<int>> curr(2,vector<int>(k+1,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=k;cap++){
                if(buy){
                    int b=-prices[i]+after[0][cap];
                    int nb=after[1][cap];
                    curr[buy][cap]=max(b,nb);
                }
                else{
                    int s=prices[i]+after[1][cap-1];
                    int ns=after[0][cap];
                    curr[buy][cap]=max(s,ns);
                }
            }
        }
        after=curr;
    }
    return after[1][k];
}
