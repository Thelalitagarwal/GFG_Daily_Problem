class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>> dp(N,vector<long long int>(3,-1));
        dp[0][0]=r[0];
        dp[0][1]=g[0];
        dp[0][2]=b[0];
        for(int i=1;i<N;i++){
            dp[i][0]=r[i]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=g[i]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=b[i]+min(dp[i-1][0],dp[i-1][1]);
        }
        return min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
    }
};
