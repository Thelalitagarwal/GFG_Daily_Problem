class Solution {
public:
	int maximumMatch(vector<vector<int>>&G){
        int m = G.size();
        int n = G[0].size();
        int match[n];
        memset(match, -1, sizeof(match));
        int res = 0;
        for (int i = 0; i < m; i++) {
            vector<bool> used(n, false);
            if (dfs(G, i, used, match)) res++;
        }
        return res;
    }
    bool dfs(vector<vector<int>>& G, int u, vector<bool>& used, int* match) {
        for (int v = 0; v < G[0].size(); v++) {
            if (G[u][v] == 1 && !used[v]) {
                used[v] = true;
                if (match[v] == -1 || dfs(G, match[v], used, match)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
};