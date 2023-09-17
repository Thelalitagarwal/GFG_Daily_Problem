class Solution{
    public:
    vector<long long> printFibb(int n) {
        vector<long long> M;
        if(n==1){
            M.push_back(1);
            return M;
        }
        M.push_back(1);
        M.push_back(1);
        for(int i=2;i<n;i++){
            M.push_back(M[i-1]+M[i-2]);
        }
        return M;
    }
};