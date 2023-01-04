class Solution {

  public:

    int maximum_profit(int n, vector<vector<int>> &intervals) {

        sort(intervals.begin(),intervals.end());

        vector<int> dp(n+1,0);

        for(int idx=n-1;idx>=0;idx--){

            vector<int> temp(3,0);

            temp[0]=intervals[idx][1];

            int next=lower_bound(intervals.begin(),intervals.end(),temp)-intervals.begin();

            int pick=intervals[idx][2]+dp[next];

            int notpick=dp[idx+1];

            dp[idx]=max(pick,notpick);            

        }

        return dp[0];

    }

};