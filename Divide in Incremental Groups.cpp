class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        vector<vector<int>> dp(N+1,vector<int>(K+1));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                if(i<j) dp[i][j]=0;
                else if(j==1) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1] + dp[i-j][j];
            }
        }
        return dp[N][K];
    }
};