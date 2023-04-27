class Solution{
public:
    vector<vector<int>> freq;
    
    void build(string &s, int cur, int l, int r) {
        if(l == r) {
            freq[cur][s[l]-'a'] = 1;
            return;
        }
        int mid = l + (r-l)/2, lchild = 2*cur + 1, rchild = 2*cur + 2;
        build(s, lchild, l, mid);
        build(s, rchild, mid+1, r);
        for(int i = 0; i < 26; i++) freq[cur][i] = freq[lchild][i] + freq[rchild][i];
    }
    
    void update(int idx, char c1, char c2, int cur, int l, int r) {
        if(l > idx || r < idx || l > r) return;
        freq[cur][c1-'a']--;
        freq[cur][c2-'a']++;
        if(l == r) return;
        int mid = l + (r-l)/2, lchild = 2*cur + 1, rchild = 2*cur + 2;
        update(idx, c1, c2, lchild, l, mid);
        update(idx, c1, c2, rchild, mid+1, r);
    }
    
    void query(int l, int r, int cur, int L, int R, vector<int>& f) {
        if(l > R || L > r) return;
        if(l <= L && R <= r) {
            for(int i = 0; i < 26; i++) f[i] += freq[cur][i];
            return;
        }
        int mid = L + (R-L)/2, lchild = 2*cur + 1, rchild = 2*cur + 2;
        query(l, r, lchild, L, mid, f);
        query(l, r, rchild, mid+1, R, f);
    }
    
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        freq = vector<vector<int>>(4*n, vector<int>(26, 0));
        build(s, 0, 0, n-1);
        vector<char> ans;
        for(auto& q : queries) {
            if(q[0] == "1") {
                int idx = stoi(q[1]);
                char c = q[2][0];
                update(idx, s[idx], c, 0, 0, n-1);
                s[idx] = c;
            } else {
                vector<int> f(26, 0);
                query(stoi(q[1]), stoi(q[2]), 0, 0, n-1, f);
                int k = stoi(q[3]), i = 25;
                while(k > 0) k -= f[i--];
                ans.push_back('a'+i+1);
            }
        }
        return ans;
    }
};