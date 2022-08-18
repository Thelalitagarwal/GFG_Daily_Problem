class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
       unordered_map<int, int> mp;
       mp[0] = -1;
       int sum = 0;
       int ans = 0;
       for(int i = 0;i<n;i++)
       {
           sum = sum + arr[i];
           if(mp.find(sum - k) != mp.end())
           {
               ans = max(ans, i - mp[sum-k]);
           }
           if(mp.find(sum) == mp.end())
               mp[sum] = i;
       }
       return ans;
    } 
};