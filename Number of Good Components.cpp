class Solution {
  public:
    bool bfs(int node,bool visited[],vector<vector<int>>& adj){
        queue<int> q;
        q.push(node);
        visited[node]=true;
        int nodes=0;
        int edges=adj[node].size();
        bool flag=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            nodes++;
            if(adj[curr].size()!=edges) flag=false;
            for(auto it:adj[curr]){
                if(visited[it]) continue;
                visited[it]=true;
                q.push(it);
            }
        }
        return flag && edges+1==nodes;
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        bool visited[V+1]={0};
        int count=0;
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                if(bfs(i,visited,adj)) count++;
            }
        }
        return count;
    }
};