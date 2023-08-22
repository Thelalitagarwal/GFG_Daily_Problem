class Solution{
    public:
    int findMinOpeartion(vector<vector<int> > m, int n){
        int cs = 0,rs = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            int c = 0,r=0;
            for(int j = 0;j<n;j++){
                    sum += m[i][j]; 
                    r += m[i][j];
                    c += m[j][i];
            }
            rs = max(rs,r);
            cs = max(cs,c);
           
        }
        int maxi = max(rs,cs);
        return maxi*n - sum;
    } 
};