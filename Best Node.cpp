class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<int> adj[N+1];
        for(int i=1; i<N; i++){
            adj[P[i]].push_back(i+1);
        }
        
        long long ans = LLONG_MIN;
        for(int i=1; i<=N; i++){
            ans = max(ans, dfs(i, adj, A, 0));
        }
        
        return ans;
    }
    
    long long dfs(int node, vector<int> adj[], vector<int> &A, bool f){
        long long ans = LLONG_MIN;
        for(int child: adj[node]){
            ans = max(ans, dfs(child, adj, A, !f));
        }
        
        long long nodeVal = A[node-1];
        if(f)
            nodeVal = -nodeVal;
        if(ans == LLONG_MIN)
            return nodeVal;
        return ans + nodeVal;
    }
};