class Solution{
    public:
    long long countWays(int N){
        vector<long long> dp(4, 0);
        
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        
        if(N<=3){
            return dp[N];
        }
        
        for(int i=4; i<=N; ++i){
            long long ways=(dp[1]+dp[2]+dp[3])%1000000007;
            dp[1]=dp[2];
            dp[2]=dp[3];
            dp[3]=ways;
        }
        
        return dp[3];
    }
};