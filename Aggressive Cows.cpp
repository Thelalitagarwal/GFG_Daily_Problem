class Solution {
  public:
    bool ispossible(int n, int k, vector<int> &stalls, int dist) {
        int coord = stalls[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (stalls[i] - coord >= dist) {
                cnt++;
                coord = stalls[i];
            }
            if (cnt == k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls){
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(n,k,stalls,mid)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};