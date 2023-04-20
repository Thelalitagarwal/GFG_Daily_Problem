class Solution{
    public:
    
    Node* findTarget(Node* root, int home){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->data == home) return curr;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    void markParents(Node* root, unordered_map<Node*, Node*> &parents, Node* target, int home){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    int ladoos(Node* root, int home, int k){
        int sol = 0;
        unordered_map<Node*, Node*> parent;
        Node* target = findTarget(root, home);
        markParents(root, parent, target, home);
        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            if(level++ > k) break;
            for(int i = 0; i < n; i++){
                Node* curr = q.front();
                q.pop();
                sol += curr->data;
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
        }
        return sol;
    }
};