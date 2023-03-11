class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, vector<vector<int>> &q) {
        vector<int> v(n);
        unordered_map<int,int> mp;
        for(int i=n-1; i>=0; i--){
            mp[a[i]]++;
            v[i]=mp[a[i]];
        }
        vector<int>ans;
        
        for(auto x:q){
            int cnt=0;
            for(int i= x[0]; i<=x[1]; i++ ){
                if(v[i]==x[2]){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};