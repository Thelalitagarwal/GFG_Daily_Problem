class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        unordered_map<int,int> ma;
        for(int i=0;i<n;i++){
            ma[a[i]]++;
        }
        sort(a,a+n,greater<int>());
        int i=0;
        int ans=0;
        while(i<n){
            if(ma[a[i]]>0){
                ans+=a[i];
                ma[a[i]]--;
                ma[a[i]-1]--;
            }
            i++;
        }
        return ans;
    }
};