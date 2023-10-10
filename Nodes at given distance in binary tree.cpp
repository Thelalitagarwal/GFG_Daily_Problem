class Solution{
public:
void solve(Node* root, Node* p,map<Node*,Node*>&mp,int target, Node* &t){
        if(!root) return;
        mp[root] = p;
        if(!t && root->data == target) t = root;  
        solve(root->left,root,mp,target,t);
        solve(root->right,root,mp,target,t);
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int>ans;
        map<Node*,Node*>par;
        Node *t = NULL;
        solve(root,NULL,par,target,t);
        queue<pair<Node*,int>>q;
        q.push({t,k});
        map<Node*,bool>mp;
        mp[t] = true;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ;i<n;i++){
                Node*temp = q.front().first;
                int orik = q.front().second;
                if(orik == 0) ans.push_back(q.front().first->data);
                q.pop();
                if(temp->left && orik > 0 && !mp[temp->left]){
                    q.push({temp->left,orik-1});
                    mp[temp->left] = true;
                }
                if(temp->right && orik > 0 && !mp[temp->right]){
                    q.push({temp->right,orik-1});
                    mp[temp->right] = true;
                }
                if(par[temp] && orik > 0 && !mp[par[temp]]){
                    q.push({par[temp],orik-1});
                    mp[par[temp]] = true;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};