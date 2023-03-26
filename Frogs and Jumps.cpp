class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        vector<int> vis(leaves + 1);
        for(int i = 0; i < n; i++) {
            if(frogs[i] <= leaves and !vis[frogs[i]]) {
                for(int j = frogs[i]; j <= leaves; j += frogs[i]) 
                    vis[j] = 1;
            }
        }
        int count = 0;
        for(int i = 1; i <= leaves; i++) {
            if(!vis[i]) count++;
        }
        return count;
    }
};