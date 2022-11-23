class Solution {
  public:
     long long int maxSumLCM(int n) {
        long long ans = 0;
        for(long long i=1;i*i<=n;i++){
            if(n%i == 0){
                ans += i;
                if(n/i != i)
                    ans += n/i;
            }
        }
        return ans;
    }
};