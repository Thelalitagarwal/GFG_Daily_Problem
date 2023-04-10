class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int,int> mp;
        for(auto it:lines){
            int s=it[0],e=it[1];
            mp[s]++;
            mp[e+1]--;
        }
        int maxi=1;
        int presum=0;
        for(auto it:mp){
            presum+=it.second;
            maxi=max(maxi,presum);
        }
        return maxi;
    }
};