class Solution{
    public:
    
    vector<pair<int,int>> pao={{0,1},{0,-1},{1,0},{-1,0}};
    int ans=0;
    
    void rec(vector<vector<char>> mat,string target, vector<vector<bool>> &visited,int m,int n,int i,int j,int cur){
        visited[i][j]=true;
        for(int y=0;y<4;y++){
            int row=i+pao[y].first;
            int col=j+pao[y].second;
            if(row>-1 && row<m && col>-1 && col<n && target[cur]==mat[row][col] && visited[row][col]==false){
                if(cur+1==target.size()){
                    ans++;
                }
                else{
                    rec(mat,target,visited,m,n,row,col,cur+1);
                }
            }
        }
        visited[i][j]=false;
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==target[0]){
                    if(target.size()==1){
                        ans++;
                    }
                    else{
                        rec(mat,target,visited,m,n,i,j,1);
                    }
                }
            }
        }
        return ans;
    }
};
