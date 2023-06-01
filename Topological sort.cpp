class Solution{
	public:
	void dfs(int start, vector<bool> &vis, stack<int> &s, vector<int> adj[]) {
	    vis[start] = 1;
	    
	    for(int nbr : adj[start]) {
	        if(!vis[nbr]) {
	            dfs(nbr, vis, s, adj);
	        }
	    }
	    s.push(start);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<bool> vis(V);
	    stack<int> s;
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, s, adj);
	        }
	    }
	    vector<int> res;
	    for(int i = 0; i < V; i++) {
	        res.push_back(s.top()); s.pop();
	    }
	    return res;
	}
};