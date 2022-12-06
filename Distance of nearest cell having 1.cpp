
/* Link to the "Distance of nearest cell having 1" Problem ==>>  https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1 
   
   Link to the complete Explaination Video ==>> https://youtu.be/7xsRW8x-ACo */


class Solution{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
    	   queue<pair<int,int>> q;
           vector<vector<int>>grid2 =grid;
           int r = grid.size();
           int c = grid[0].size();
           int level = 0,rtemp,ctemp,size;
           for(int i=0;i<r;++i){
               for(int j=0;j<c;++j){
                   if(grid[i][j]==1)
                       q.push({i,j});
               }
           }
           
           while(!q.empty()){
               ++level;
               size=q.size();
               while(size-->0){
                   rtemp = q.front().first;
                   ctemp = q.front().second;
                   q.pop();
                   if(rtemp>0 && grid[rtemp-1][ctemp]==0){
                       q.push({rtemp-1,ctemp});
                       grid[rtemp-1][ctemp]=level;
                   }
                   if(ctemp>0 && grid[rtemp][ctemp-1]==0){
                       q.push({rtemp,ctemp-1});
                       grid[rtemp][ctemp-1]=level;
                   }
                   if(rtemp<r-1 && grid[rtemp+1][ctemp]==0){
                       q.push({rtemp+1,ctemp});
                       grid[rtemp+1][ctemp]=level;
                   }
                   if(ctemp<c-1 && grid[rtemp][ctemp+1]==0){
                       q.push({rtemp,ctemp+1});
                       grid[rtemp][ctemp+1]=level;
                   }
               }
           }
           
           for(int i=0;i<r;++i){
               for(int j=0;j<c;++j){
                   if(grid2[i][j]==1){
                       grid[i][j]=0;
                   }
               }
           }
           return grid;
	}
};
