class Solution{
    public:
    int mod=1e9+7;
    int solve(int i,int j,int &n,vector<int>&pre,vector<vector<int>>&dp){
        if(i>=pre.size() or j>n){
            return 0;
        }
        if(j==n){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=(solve(i+1,j+pre[i],n,pre,dp)+solve(i+1,j,n,pre,dp))%mod;
    }
    int numOfWays(int n, int x){
        int limit=0;
        for(int i=1;i<=n;i++){
            if(n<=pow(i,x)){
                limit=i;
                break;
            }
        }
        vector<int>pre(limit+2,0);
        for(int i=1;i<=limit+1;i++){
            pre[i]=pow(i,x);
        }
        vector<vector<int>>dp(limit+2,vector<int>(n+1,-1));
        return solve(1,0,n,pre,dp);
    }
};