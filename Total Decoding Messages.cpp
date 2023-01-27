class Solution {
 public:
 int mod=1e9+7;
 int CountWays(string str){
    if(str[0]=='0')return 0;
    int n=str.size();
    vector<int>v(n+1,0);
    v[0]=1;
    v[1]=1;
    for(int i=2; i<=n;i++){
        if(str[i-1]>'0')v[i]=v[i-1];
        if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<'7'))
        v[i]=(v[i]+v[i-2])%mod;
    }
    return v[n];
 }
};