class Solution{
	public:
    vector<int> FactDigit(int N)
    {
        vector<int>v;
        int r=1;
        int i;
        for(i=1;i<10;i++){
            r*=i;
        }
        i--;
        
        while(N>0)
        {
            int f=N/r;
            while(f>0)
            {
                v.push_back(i);
                f--;
            }
            N%=r;
            r/=i;
            i--;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};