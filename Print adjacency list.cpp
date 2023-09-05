class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adjList(V);
        for(auto edge: edges){
            int u = edge.first;
            int v = edge.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }
};