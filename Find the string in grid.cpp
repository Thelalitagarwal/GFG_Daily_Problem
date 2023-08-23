class Solution {
public:
bool f(int x,int y,int dx,int dy,int ind,string word, vector<vector<char>>grid){
    if(ind==word.size()){
        return true;
    }
       int xi = dx + x;
       int yj = dy + y;
    
        if(xi>=0 && yj>=0 && xi<grid.size() && yj<grid[0].size()){
            if(grid[xi][yj]==word[ind]){
                
                if(f(xi,yj,dx,dy,ind+1,word,grid))
                return true;
            }
        }
    return false;
}
vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    set<vector<int>> result_set;
    
    int dx[] = {1,0,-1,0,1,1,-1,-1};
    int dy[] = {0,1,0,-1,-1,1,1,-1};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==word[0]){
                for(int k=0;k<8;k++){
                      
                    if(f(i,j,dx[k],dy[k],1,word,grid)){
                       result_set.insert({i,j}); 
                    }
                }
            }
        }
    }
    vector<vector<int>> ds(result_set.begin(), result_set.end());
    return ds;
}
};