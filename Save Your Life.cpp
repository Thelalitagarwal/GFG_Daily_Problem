class Solution{
public:
      string maxSum(string s, char x[], int b[], int n){
          unordered_map<char, int> mp;
          for(int i=0; i<n; i++) 
            mp[x[i]] = b[i];
          
          int ans = INT_MIN, curr = 0;
          string temp, res;

          for(int i=0; i<s.length(); i++) {
              if(mp.find(s[i]) != mp.end())
                curr += mp[s[i]];
              else{
                curr += s[i];
              }
              
              temp += s[i];
              if(curr > ans) {
                  ans = curr;
                  res = temp;
              }
              if(curr < 0) {
                  curr = 0;
                  temp = "";
              }
          }
          return res;
      }
};