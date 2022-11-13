class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        long long mod=1e9+7;
        sort(capacity.begin(),capacity.end());
        long long sum=1;
        for(int i=0;i<n;i++)
        {
            capacity[i]=capacity[i]-i;
            sum=(sum*capacity[i])%mod;
        }
        return (sum)%mod;
    }
};