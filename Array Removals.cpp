class Solution{
    public:
    int removals(vector<int>& a, int k){
        sort(a.begin(), a.end());
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++){
            auto j=upper_bound(a.begin(), a.end(), a[i]+k)-a.begin()-1;
            int t=j-i+1;
            ans=max(ans, t);
        }
        return n-ans;
    }
};