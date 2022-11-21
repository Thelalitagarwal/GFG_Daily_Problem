class Solution{
    public:
        void helper(vector<vector<int>>&ans,vector<int>&curr,int i,int n){
            if(n==0){
                ans.push_back(curr);
                return;
            }
            if(i<1){
                return;
            }
            if(i<=n){
                curr.push_back(i);
                helper(ans,curr,i,n-i);
                curr.pop_back();
                helper(ans,curr,i-1,n);
            }
            else{
                helper(ans,curr,i-1,n);
            }
        }
        
        vector<vector<int>> UniquePartitions(int n) {
            vector<vector<int>>ans;
            vector<int>curr;
            helper(ans,curr,n,n);
            return ans;
        }
};