class Solution{
    public:
    int findMinTime(int N, vector<int>&A, int L){
          vector<int>ans;
           for(auto it:A){
               int ele = it;
               ans.push_back(it);
               for(int i=2;i<=N;++i){
                   int x = ans.back()+(i*ele);
                   ans.push_back(x);
               }
           }
           sort(ans.begin(),ans.end());
           return ans[N-1];
    }
};
