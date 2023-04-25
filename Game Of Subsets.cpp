class Solution{
public:
 int mod;
    vector<int> mp;
    Solution(){
        mod=1e9+7;
        mp.resize(31);
        vector<int>prime={2,3,5,7,11,13,17,19,23,29};
        for(int i=2; i<=30; ++i){
            if(0 == i%4 || 0 == i%9 || 25 == i) continue;
            int mask=0;
            for(int j=0; j<10; ++j){
                if(0 ==i%prime[j]) mask |= 1<<j;
            }
            mp[i]=mask;
        }
    }
    long pow(int n){
        long ans=1, m=2;
        while(n!=0){
            if(1 == (n&1)) ans=(ans*m)%mod;
            m=m*m%mod;
            n>>=1;
        }
        return ans;
    }
    int goodSubsets(vector<int> &arr, int n){
        int one=0;
        vector<int> dp(1024), cnt(31);
        dp[0] =1;
        for(int i: arr){
            if(i == 1)
                one++;
            else if(mp[i]!=0)
                cnt[i]++;
        }
        for(int i=0; i<31; ++i){
            if(cnt[i] == 0) continue;
            for(int j=0; j<1024; ++j){
                if(0 != (j &mp[i]) ) continue;
                dp[j | mp[i]] = 
                    (int) ((dp[j | mp[i]] + dp[j] * (long)cnt[i]) % mod);
                   
            }
        }
        
        
        long ans=0; 
        for(int i:dp) ans = (ans+i) % mod;
        ans--;
        if(one!=0) ans=ans*pow(one)%mod;
        return (int)ans;
    }
};
