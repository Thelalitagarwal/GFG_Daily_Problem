class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int left=0;
        int cnt=0;
        long long prod=1;
        for(int right=0;right<n;right++){
            prod*=a[right];
            while(prod>=k&&left<n){
                prod/=a[left];
                left++;
            }
            if(prod<k)cnt+=right-left+1;
        }
        return cnt;
    }
};