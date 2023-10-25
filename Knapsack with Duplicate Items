class Solution{
    public:
    int knapSack(int N, int W, int val[], int wt[]){
        int dp[W+1];
        dp[0] = 0;
        int max = 0;
        int tbagc = 0;
        for(int bagc = 1;bagc<=W;bagc++) {
            max = 0;
            for(int j = 0;j<N;j++) {
                if(wt[j] <= bagc) {
                    int rbagc = bagc - wt[j];
                    tbagc = val[j] + dp[rbagc];
                }
                if(max < tbagc) {
                    max = tbagc;
                }
            }
            dp[bagc] = max;
        }
        return dp[W];         

    }
} ;
