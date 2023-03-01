class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U){
            // code here
            vector<int>ans(N,0); 
            vector<vector<int>>pref(N,vector<int>(31,0));
            for(int i = 0; i < Q; i++){
                int l = U[i][0]-1,r = U[i][1],x = U[i][2];
                for(int j = 0; j < 31; j++){
                    int mask = 1 << j;
                    if(mask & x){
                        pref[l][j]++;
                        if(r < N){
                            pref[r][j]--;
                        }
                    }
                }
            }
            for(int i = 1; i < N; i++){
                for(int j = 0; j < 31; j++){
                    pref[i][j] += pref[i-1][j];
                }
            }
            for(int i = 0; i < N; i++){
                int a = 0;
                for(int j = 0; j < 31; j++){
                    if(pref[i][j]){
                        a |= (1 << j);
                    }
                }
                ans[i] = a;
            }
            return ans;
        }
};