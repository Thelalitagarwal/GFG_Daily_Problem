class Solution {
  public:
    int isItPossible(string s, string t, int m, int n) {
        string s1,s2;
        for(int i=0;i<m;i++){
            if(s[i]!='#') s1.push_back(s[i]);
        }
        for(int i=0;i<n;i++){
            if(t[i]!='#') s2.push_back(t[i]);
        }
        return s1==s2;
    }
};