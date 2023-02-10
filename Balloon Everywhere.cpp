class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)  mp[s[i]]++; 
        int a=INT_MAX;
        a=min(mp['b'],min(mp['a'],min(mp['n'],min(mp['l']/2, mp['o']/2))));
        return a;
    }
};