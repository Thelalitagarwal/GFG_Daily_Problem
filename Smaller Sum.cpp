class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> a(n+1,0);
        vector<long long> ans(n,0);
        vector<long long> val(n,0);
        for(int i=0;i<n;i++)
        val[i]=arr[i];
        long sum=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            sum+=arr[i];
            a[i+1]=sum;
        }
        for(int i=0;i<n;i++)
        {
            int x=lower_bound(arr.begin(),arr.end(),val[i])-arr.begin();
            ans[i]=a[x];
        }
        return ans;
    }
};