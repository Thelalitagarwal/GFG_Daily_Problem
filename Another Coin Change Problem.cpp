class Solution {
  public:
      bool solve(vector<vector<vector<int>>>&dp, int i, int k, int target, vector<int>&arr){
      if(i>=arr.size())return false;
      if(k==0 and target==0)return true;
      if(dp[i][target][k]!=-1)return dp[i][target][k];
      
      if(target>=arr[i]){
          return dp[i][target][k] = solve(dp,i,k-1,target-arr[i], arr)|| solve(dp,i+1,k,target,arr);
      }
      else return dp[i][target][k] =  solve(dp,i+1,k,target,arr);
  }
    bool makeChanges(int n, int k, int target, vector<int> &arr) {
        // code here
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(target+1, vector<int>(k+1,-1)));
        return solve(dp,0,k,target, arr);
    }
};