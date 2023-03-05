class Solution {
  public:
    vector<int> parent;
    int findParent(int node)
    {
        if(node==parent[node])
           return node;
        return parent[node] = findParent(parent[node]);   
    }
    void Union(int u,int v)
    {
        int ul_parentU = findParent(u);
        int ul_parentV = findParent(v);
        if(ul_parentU==ul_parentV)
            return;
        parent[ul_parentU]   = ul_parentV; 
    }
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
            vector<string> ans;
            parent = vector<int> (n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
            //Logic
            //Traverse into mix array
            for(int i=0;i<n;i++){
                //Find out both's parent
                int a = findParent(mix[i][0]);
                int b = findParent(mix[i][1]);
                //Now traverse into danger array
                bool canMix = true;
                for(int j=0;j<m;j++){
                    //Find out parent of those
                    int c = findParent(danger[j][0]);
                    int d = findParent(danger[j][1]);
                    //Check if parent are same then
                    if((a==c && b==d) || (a==d && b==c)){
                        canMix = false;
                        break;
                    }
                }
                //If canMix True means no explosion is there
                if(canMix){
                    Union(a,b);
                    ans.push_back("Yes");
                }else{
                    ans.push_back("No");
                }
            }
            return ans;
        }
};