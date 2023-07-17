class Solution {
    public:
        string FirstNonRepeating(string A){
            unordered_map<char,int> mp;
            queue<char> q;
            string ans="";
            
            for(char c: A){
                mp[c]++;
                if(mp[c]==1){
                    q.push(c);
                }
                while(!q.empty() && mp[q.front()]>1){
                    q.pop();
                }
                if(q.empty()){
                    ans+='#';
                }else{
                    ans+=q.front();
                }
            }
            return ans;
        }
};