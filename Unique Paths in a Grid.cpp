class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        int mod = (int)1e9+7;
        vector<vector<int>> paths(n, vector<int>(m, 0));
        if (grid[0][0]==0 || grid[n-1][m-1]==0) return 0;
            paths[0][0] = 1;
        for(int i = 1; i < n; i++){
            if (grid[i][0]==0) break;
            else paths[i][0] = 1;
        }
        for(int j = 1; j < m; j++){
            if (grid[0][j]==0) break;
            else paths[0][j] = 1;
        }  
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if (grid[i][j] == 1)
                    paths[i][j] = (paths[i - 1][j] % mod +
                                  paths[i][j - 1] % mod) % mod;
            } 
        }
        return paths[n - 1][m-1]%mod;
    }
};