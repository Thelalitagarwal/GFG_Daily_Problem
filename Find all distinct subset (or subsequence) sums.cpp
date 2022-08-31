class Solution {
    set<int> s;
    int dp[101][10001];
    int n;
public:
    int rec(int ind, int sum, vector<int>& nums){
        if(ind == n)    {s.insert(sum); return 1;}
        if(dp[ind][sum] != -1)   return dp[ind][sum];
        int take = rec(ind+1, sum+nums[ind], nums);
        int nontake = rec(ind+1, sum, nums);
        
        return dp[ind][sum] = take + nontake;
    }
	vector<int> DistinctSum(vector<int>nums){
	    n = nums.size();
	    memset(dp, -1, sizeof(dp));
	    rec(0, 0, nums);
	    vector<int> res;
	    for(auto val: s)    res.push_back(val);
	    return res;
	}
};