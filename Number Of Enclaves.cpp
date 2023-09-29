class Solution {
  public:
    void move(vector<vector<int>> &grid,int i,int j){
        int r=grid.size();
        int c=grid[0].size();
        if(i<0 || i==r || j<0 || j==c || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        move(grid,i+1,j);
        move(grid,i-1,j);
        move(grid,i,j+1);
        move(grid,i,j-1);
        return;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int counter=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || j==0 ||i==r-1 || j==c-1) && grid[i][j]==1)
                move(grid,i,j);
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    counter++;
                }
            }
        }
        return counter;
    }
};