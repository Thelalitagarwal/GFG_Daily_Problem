class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
    
        long long int temp=0;
        for(int i=0;i<N;i++) temp=temp^Arr[i];
        long long int n1=0,n2=0,rsetbit=temp & -temp;
        for(int i=0;i<N;i++){
            if(Arr[i] & rsetbit) n1^=Arr[i];
            else n2^=Arr[i];
        }
        vector<long long int> ans({n1,n2});
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};