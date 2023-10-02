class Solution{
  public:	
	int distinctSubsequences(string s){ 
	    int m[26]={-1};
        int n=s.length();
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=0;i<s.length();i++){
            if(m[s[i]-'a']!=-1)
                dp[i+1]=((dp[i]*2)%1000000007)-dp[m[s[i]-'a']-1]+1000000007; 
            else
                dp[i+1]=(dp[i]*2);
            m[s[i]-'a']=i+1;
            dp[i+1]=dp[i+1]%1000000007;
        }
        return dp[s.length()]%1000000007;
    }
};