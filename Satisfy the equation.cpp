class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        unordered_map<int,pair<int,int>>mp;
        vector<int>ans;
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                int sum=A[i]+A[j];
                if(mp.find(sum)!=mp.end())
                {
                    if(mp[sum].first!=i && mp[sum].second!=i && mp[sum].first!=j && mp[sum].second!=j)
                    {
                        vector<int>v={mp[sum].first,mp[sum].second,i,j};
                        if(ans.size()==0 || ans>v)
                        ans=v;
                    }
                }
                else
                mp[sum]={i,j};
            }
        }
        if(ans.empty()){
        vector<int>v={-1,-1,-1,-1};
        return v;
        }
        return ans;
    }
};