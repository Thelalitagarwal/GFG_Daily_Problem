class Solution {
public:
    int minimumSwaps(int c[],int v[],int n,int k,int b,int T)
    {
        // code here
        int ans=0;
        vector<int> vec;
        for(int i=0;i<n;i++)
            vec.push_back(c[i]+v[i]*T);
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            
            if(vec[i]>=b)
            {
                if(count>0)
                    ans+=count;
                k--;
            }
            else
                count++;
            if(k==0)
                return ans;
        }
        return -1;
    }
};