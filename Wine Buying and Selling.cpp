class Solution{
    public:
        long long int wineSelling(vector<int> &arr,int size){
            long long ans=0;
            int p=0,n=0;
            while(1) {
                while(arr[p]<=0 && p<size) {
                    p++;
                }
                while(arr[n]>=0 && n<size) {
                    n++;
                }
                if(p==size || n==size) {
                    break;
                }
                int x=min(arr[p],-arr[n]);
                arr[p]-=x;
                arr[n]+=x;
                ans+=x*abs(p-n);
            }
            return ans;
        }
};