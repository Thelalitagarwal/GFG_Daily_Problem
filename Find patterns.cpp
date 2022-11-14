class Solution{   
public:
    int numberOfSubsequences(string S, string W) {
        int k;
        int ans=0;
        for(int i=0;i<S.size();i++) {
            if(S[i]==W[0]) {
                k=0;
                for(int j=i;j<S.size() && k<W.size();j++) {
                    if(S[j]==W[k]){
                        S[j]='@';
                        k++;
                    }
                }
                if(k==W.size())
                    ans++;
            }
        }
        return ans;
    }
};