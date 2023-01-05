class Solution{
public:
    string longestString(vector<string> &words){
        unordered_map<string,int> m;
        sort(words.begin(),words.end());
        for(auto i:words) m[i]++;
        string ans;
        int size=INT_MIN;
        for(auto i:words) {
            string temp;
            int c=0,n=i.size();
            for(int j=0;j<n;j++){
                temp+=i[j];
                if(m[temp]) c++;
            }
            if(c==n && n>size) {
                size=n; 
                ans=i;
            }
        }
        return ans;
    }
};