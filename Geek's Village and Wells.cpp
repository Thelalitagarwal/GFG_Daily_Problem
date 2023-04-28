class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='N') {
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
                if(c[i][j]=='W'){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                }
                if(c[i][j]=='.') ans[i][j]=0;
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newi = row + dx[i];
                int newj = col + dy[i];
                if(newi>=0&&newi<n&&newj>=0&&newj<m&&vis[newi][newj]==0&&(c[newi][newj]=='H'||c[newi][newj]=='.'))
                {
                    if(c[newi][newj]=='H') ans[newi][newj] = 2*(dis+1);
                    q.push({dis+1,{newi,newj}});
                    vis[newi][newj]=1;
                }
            }
        }
        return ans;
    }
};