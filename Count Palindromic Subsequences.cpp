class Solution{
    public:
    long long  dp[1001][1001];
    
    int mod=1e9+7;
    
    long long solve(string &str,int i,int j){
        if(i>j)return 0;
         
        if(i==j)return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(str[i]==str[j])
            return dp[i][j]=(1+solve(str,i+1,j)+solve(str,i,j-1))%mod;
        else
            return dp[i][j]=(mod+solve(str,i+1,j)+solve(str,i,j-1)-solve(str,i+1,j-1))%mod;
    }
    
    long long int  countPS(string str)
    {
     memset(dp,-1,sizeof(dp));
     return solve(str,0,str.size()-1);
    }
};