class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        int i=0, j=0;
        if(M!=N) return 0;
        while(i<M || j<N){
            while(S[i]=='#') i++;
            while(T[j]=='#') j++;
            if(i>=M && j<N) return 0;
            if(i<M && j>=N) return 0;
            if(S[i]!=T[j]) return 0;
            else{
                if(S[i]=='A' && i<j) return 0;
                else if(S[i]=='B' && i>j) return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
};

