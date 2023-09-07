class Solution {
  public:
   int mod=(int)1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        vector<int> vis(1e5,-1);
        ans=INT_MAX;
        queue<pair<int,int>> q;
        int count=1;
        q.push({0,start});
        vis[start]=1;
        while(!q.empty()){
            int a=q.front().second;
            int dist=q.front().first;
            q.pop();
            
            for(auto it:arr){
                int x=(it%mod*a%mod)%mod;
                if(x==end) ans=min(dist+1, ans) ;
                if(vis[x]==-1){
                    vis[x]=1;
                    q.push({dist+1,x});
                }
            }
        }
        if(ans!=INT_MAX) return ans;
        return -1;
    }
};