class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        int ans = 0;
        for(int i = 0; i < N - 1; i++){
            while(S[i+1] == S[i] && S[i] != '?')
                S[P[ans++]] = '?';
        }
        return ans;
    }
};