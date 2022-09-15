class Solution{
    public:
    int minSubset(vector<int> &arr,int n){

        sort(arr.rbegin(),arr.rend());
        vector<long long>sum(n);
        sum[0]=arr[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+arr[i];
        }
        long long total=sum[n-1];
        for(int i=0;i<n;i++){
            if((total-sum[i])<sum[i]){
                return i+1;
            }
        }
        return n;
    }
};