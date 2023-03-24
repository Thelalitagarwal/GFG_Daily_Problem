class Solution {
  public:
    string removeReverse(string s) {
        int n = s.length() ;
        int i = 0;
        int j = s.length()-1 ;
        unordered_map<char,int> mp ;
        for(auto it : s){
            mp[it]++;
        }
        bool flag=true ;
        while( i <= j ){
            if( flag ){
                if( mp[s[i]]>1){
                  mp[s[i]]--;
                  s[i] = '0' ;
                  flag=false;
                  
                }
                i++;
            }
            else {
                if( mp[s[j]]>1) {
                    mp[s[j]]-- ;
                    s[j]='0' ;
                    flag = true ;
                }
                j--;
            }
        }
        string ans ;
        for(auto it : s ){
            if( it != '0' )
            ans+=it ;
        }
        if( flag )
        return ans;
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};