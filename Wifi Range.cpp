class Solution{
    public:
    bool wifiRange(int n, string s, int x){
       vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                v.push_back(i);
            }
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]-v[i]-1>2*x){
                return false;
            }
        }
        if(v[0]>x) return false;
        if(n-1-v[v.size()-1]>x) return false;
        
        return true;
    }
};