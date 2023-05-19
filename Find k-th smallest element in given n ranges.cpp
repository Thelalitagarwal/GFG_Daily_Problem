class Solution{
    public:
    int query(int q, vector<vector<int>>& range) {
        int n = range.size();
        int last = 0;
        for(int i = 0; q > 0 && i < n; i++) {
            int start = max(last+1, range[i][0]);
            int end = range[i][1];
            if(start > end) continue;
            int len = end-start+1;
            if(q <= len) return start+q-1;
            q -= len;
            last = end;
        }
        return -1;
    }
    
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end(), [](vector<int>& r1, vector<int>& r2) {
            if(r1[0] != r2[0]) return r1[0] < r2[0];
            return r1[1] < r2[1];
        });
        vector<int> ans;
        for(int q : queries) {
            ans.push_back(query(q, range));
        }
        return ans;
    } 
};