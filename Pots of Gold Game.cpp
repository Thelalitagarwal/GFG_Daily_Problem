class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    vector<vector<int>>dp(n,vector<int>(n));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=A[i];
                }
                else if(g==1){
                    dp[i][j]=max(A[i],A[j]);
                }
                else{
                    int val1=A[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int val2=A[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j]=max(val1,val2);
                }
            }
        }
        return dp[0][n-1];
    }
};
