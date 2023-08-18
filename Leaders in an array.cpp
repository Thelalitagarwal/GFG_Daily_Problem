class Solution{
    public:
    vector<int> leaders(int a[], int n){
        vector<int>ans;
        int maxi=a[n-1];
        ans.push_back(a[n-1]);
        for(int i=n-2;i>=0;i--){
             maxi=max(maxi,a[i+1]);
            if(a[i]>=maxi){
                ans.push_back(a[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};