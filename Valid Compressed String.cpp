class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i = 0; 
        int j = 0;
        int n = S.size();
        int m = T.size();
        while(i<n && j<m){
            if(isdigit(T[j])){
                int count = 0;
                while (j <m  && isdigit(T[j])) {
                   count = count * 10 + (T[j] - '0');
                     j++;
                }
                 i += count;
            }
            else if(S[i] == T[j]){
                i++;
                j++;
            }else if(S[i] != T[j]) return 0;
        }
        return i == n && j == m;
    }
};