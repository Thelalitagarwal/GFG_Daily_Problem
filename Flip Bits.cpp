class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int mx=0,c=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(c<0)c=0;
            if(c>=0)
            {
                if(a[i]==0)
                {
                    c++;
                    mx=max(mx,c);
                }
                else{
                    cnt++;
                    c--;
                }            }
        }
        return (cnt+mx);
    }
};