class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int ans[2];
        for(int i=0;i<n;i++){
            if(a[i]==0){
                ans[0]++;
            }
            else if(a[i]==1){
                ans[1]++;
            }
        }
        cout<<ans[0]<<" "
        for(int i=0;i<n;i++){
            if(ans[0]>0){
                a[i]=0;
                ans[0]--;
            }
            else if(ans[1]>0){
                a[i]=1;
                ans[1]--;
            }
            else{
                a[i]=2;
            }
        }
    }
};
