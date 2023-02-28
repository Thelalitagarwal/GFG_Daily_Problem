class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &arr){
        vector<int> ans;
        vector<int> sum(n,0);
        sum[0]=arr[0];
        ans.push_back(0);
        for(int i=1;i<n;i++){
            sum[i]+=sum[i-1]+arr[i];
            int curr=0;
            if(i%2==0){
                int j=i/2;
                int sum1 = sum[j-1];
                int sum2 = sum[i]- sum[j];
                curr=sum2-sum1;
            }
            else{
                int j=i/2;
                int sum1=sum[j];
                int sum2=sum[i]-sum[j];
                curr=sum2-sum1;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};