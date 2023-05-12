class Solution {
  public:
    int arrayOperations(int n, vector<int> v) {
        vector<int> a;
        a.push_back(-1);
        for(int i=0; i<n; i++) 
        if (v[i]==0) a.push_back(i);
        a.push_back(n);
        int cnt=0;
        for(int i=0; i<a.size()-1; i++) if (a[i+1]-a[i] > 1)cnt++;
        return cnt;
    }
};