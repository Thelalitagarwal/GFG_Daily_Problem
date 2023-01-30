/*
Link to the "Select Nodes" Problem ==>> https://practice.geeksforgeeks.org/problems/f7bfa137576243795abb0595962d61b632bbad21/1

Link to the complete Explaination Video ==>> https://youtu.be/WKFDy3wjswA 

*/

class Solution{
  public:
    void dfs(const vector<vector<int>>& nodes, const int src, const int par, vector<pair<int, int>>& dp) {
    	for (const auto & i : nodes[src]){
    		if (i != par) 
    		dfs(nodes, i, src, dp);
    	}
    	for (const auto& i : nodes[src]){
    		if (i != par) {
    			dp[src].first += dp[i].second;
    			dp[src].second += min(dp[i].first, dp[i].second);
    	    }
    	}
    }   

    int countVertex(int N, vector<vector<int>>edges){
    	vector<vector<int>> nodes(N);
    	for (const auto & e : edges) {
    		nodes[e[0] - 1].push_back(e[1] - 1);
    		nodes[e[1] - 1].push_back(e[0] - 1);
    	}
    	vector<pair<int, int>> dp(N, { 0, 1 });
    	dfs(nodes, 0, 0, dp);
    	return min(dp[0].first, dp[0].second);
    }
};