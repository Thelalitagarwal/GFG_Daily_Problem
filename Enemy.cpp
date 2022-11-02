class Solution{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy){
            if(k==0) return m*n;
            vector<int> rows(n,0);
            vector<int> col(m,0);
            for(int i=0;i<enemy.size();i++){
                rows[enemy[i][0]-1]=-1;
                col[enemy[i][1]-1]=-1;
            }
            int maxRow=0;
            int cntR=0;
            for(int i=0;i<n;i++){
                if(rows[i]!=-1) cntR++;
                else cntR=0;
                if(cntR>maxRow) maxRow=cntR;
            }
            int maxCol=0;
            int cntC=0;
            for(int i=0;i<m;i++){
                if(col[i]!=-1) cntC++;
                else cntC=0;
                if(cntC>maxCol)
                maxCol=cntC;
            }
            return maxRow*maxCol;
        }
};