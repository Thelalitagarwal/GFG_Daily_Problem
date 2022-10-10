class Solution {
  public:
    void DFS(vector<vector<int>> &M, int i, int j, int ROW, int COL){
        
        if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1) 
            return;
    
        if (M[i][j] == 1)
        {
            M[i][j] = 0;
            DFS(M, i + 1, j, ROW, COL);     
            DFS(M, i - 1, j, ROW, COL);     
            DFS(M, i, j + 1, ROW, COL);     
            DFS(M, i, j - 1, ROW, COL);     
        }
    }
 
    int countIslands(vector<vector<int>> M){
        
        int ROW = M.size();
        
        int COL = M[0].size();
        
        int count = 0;
        
        for (int i = 0; i < ROW; i++){
            
            for (int j = 0; j < COL; j++){
                
                if (M[i][j] == 1){
                    count++;
                    DFS(M, i, j, ROW, COL);
                }
            }
        }
        return count;
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<vector<int>> island(n,vector<int> (m,0));
        
        vector<int> v;
        
        for(int i=0; i<operators.size(); i++)
        {
            
            int x = operators[i][0];
            int y = operators[i][1];
            
            if(island[x][y]!=1){
                
                island[x][y] = 1;
                
                v.push_back(countIslands(island));
            }
            else{
                
                int xx = v[v.size()-1];
                
                v.push_back(xx);
            }
        }
        return v;
    }
};