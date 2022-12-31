class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        map<int,int>m;
        for(int i=0; i<N; i++){
            m[start[i]] += 1;
            m[end[i]] -= 1;
        }
        vector<pair<int,int>> vec;
        for(auto it: m) vec.push_back(it);
        int c=0,ans=0;
        for(pair<int,int> i:vec){
            c+=i.second;
            ans=max(ans,c);
        }
        return ans;
    }
};