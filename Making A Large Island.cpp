class Solution{
public:
    int largestIsland(vector<vector<int>>& grid) {
    int maxcount = INT_MIN;
    int n = grid.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int flag =0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                flag =1;
                grid[i][j] = 1;
                maxcount = max(maxcount, dfs(grid, i, j, n, vis));
                grid[i][j] = 0;
            }
            for (int k = 0; k < n; k++) {
                    fill(vis[k].begin(), vis[k].end(), 0);
                }
        }
    }
    if(flag==0){
        return n*n;
    }
    return maxcount;
}

int dfs(vector<vector<int>>& grid, int i, int j, int n, vector<vector<int>>& vis) {
    vis[i][j] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y] && grid[x][y] == 1) {
            vis[x][y] = 1;
            dfs(grid, x, y, n, vis);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 1) {
                count++;
            }
        }
    }
    return count; 
}

};