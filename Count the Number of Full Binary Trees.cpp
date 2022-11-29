class Solution{
public:
    
    long long int numoffbt(long long int arr[], int n){
        const long long int MOD = 1000000007;
        long long int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            mn = (mn > arr[i]) ? arr[i] : mn;
            mx = (mx < arr[i]) ? arr[i] : mx;
        }
        long long int ans = 0;
        int pd;
        vector<bool> vis(mx+1, false);
        vector<long long int> sol(mx+1, 0);
        for(int i = 0; i < n; i++){
            vis[arr[i]] = 1;
            sol[arr[i]] = 1;
        }
        for(int i = mn; i <= mx; i++){
            if(!vis[i]){
                continue;
            }
            for(int j = 2; i*j <= mx && j <= i; j++){
                pd = i*j;
                if(!vis[pd]){
                    continue;
                }
                sol[pd] = (sol[pd] + (sol[i]*sol[j])%MOD)%MOD;
                if(i != j){
                    sol[pd] = ( sol[pd] + (sol[i]*sol[j])%MOD)%MOD;
                }
            }
            ans = (ans + sol[i])%MOD;
        }
        return ans;
    }
};