class Solution {
  public:
    int newK(int k, int n){
        int t = log2(n);
        if(pow(2, t) == n) return k/2;
        return k*2;
    }
    string lexicographicallySmallest(string st, int k) {
        int n = st.length();
        vector<bool> vis(n, false);
        stack<int> s;
        string ans = "";
        k = newK(k, n);
        if(k >= n){
            ans = "-1";
            return ans;
        }
        if(k == 0){
            return st;
        }
        s.push(0);
        int i = 1;
        while(i < n){
            while(st[s.top()] > st[i]){
                vis[s.top()] = true;
                k--;
                s.pop();
                if(s.empty() or k == 0) break;
            }
            if(k == 0) break;
            s.push(i);
            i++;
        }
        while(k > 0 and !s.empty()){
            vis[s.top()] = true;
            k--;
            s.pop();
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]) ans += st[i];
        }
        return ans;
    }
};