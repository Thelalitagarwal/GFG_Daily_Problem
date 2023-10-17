class Solution{
public:
    void setDfs(vector<int> adj[], vector<int> &visited, int index) {
        visited[index] = 1;
        for (auto x: adj[index]) {
            if (visited[x] != 1) {
                setDfs(adj, visited, x);
            }
        }
        
        return;
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph){
        vector<int> adj[N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && graph[i][j]==1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < N; i++) {
            vector<int> visited(N, 0);
            visited[i] = 1;
            setDfs(adj, visited, i);
            ans.push_back(visited);
        }
        
        return ans;
    }
};