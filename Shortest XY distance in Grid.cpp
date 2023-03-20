class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        int ans=INT_MAX;
        
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int r=it.first.first;
            int c=it.first.second;
            int dist=it.second;
            if(grid[r][c]=='Y'){
                return dist;
            }
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==0){
                    q.push({{nr,nc},dist+1});
                    vis[nr][nc]=1;
                }
            }
        }
        
        return -1;
        
    }
};