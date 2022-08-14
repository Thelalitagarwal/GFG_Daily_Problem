class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int M = 1000000000 + 7;
        vector<long long int> dp(n+1);
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 2;i<=n;i++)
            dp[i] = ((dp[i-1]%M) + (i-1)*((dp[i-2])%M))%M;
        return dp[n];
    }
};  