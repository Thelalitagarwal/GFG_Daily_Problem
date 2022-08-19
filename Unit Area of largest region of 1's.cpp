void findbfs(int n, int m, vector<vector<int>>&vis, vector<vector<int>>& grid, int &maxi, int i, int j){
       queue<pair<int,int>>q;
       q.push({i,j});
       vis[i][j]=1;
       maxi++;
       while(!q.empty()){
               auto it=q.front();
               q.pop();
               int a=it.first;
               int b=it.second;
               vector<pair<int,int>>chk={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
               for(int ind=0;ind<8;ind++){
                   int x=a+chk[ind].first;
                   int y=b+chk[ind].second;
                   if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && vis[x][y]==0){
                      q.push({x,y});
                      vis[x][y]=1;
                      maxi++;
                   }
               }
       }
   }
   
   int findMaxArea(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int ans=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               int maxi=0;
               if(grid[i][j]==1 && vis[i][j]==0){
                   findbfs(n,m,vis,grid,maxi,i,j);
               }
               ans=max(maxi,ans);
           }
       }
       return ans;
   }