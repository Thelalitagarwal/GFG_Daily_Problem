class Solution{   
public:
    int minCost(vector<vector<int>> &C, int N) {
        // Write your code here.
        vector<vector<long long int>> dp(N,vector<long long int>(3,-1));
        dp[0][0]=C[0][0];
        dp[0][1]=C[0][1];
        dp[0][2]=C[0][2];
        for(int i=1;i<N;i++){
            dp[i][0]=C[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=C[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=C[i][2]+min(dp[i-1][0],dp[i-1][1]);
        }
        return min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
    }
};