void dfs(Node* root, unordered_map<int, int>& hash) {
    if(!root)
        return ;
    
    if(root->left)
        hash[root->left->data] = root->data;
        
    if(root->right)
        hash[root->right->data] = root->data;
        
    dfs(root->left, hash);
    dfs(root->right, hash);
}

int kthAncestor(Node *root, int k, int node){
    unordered_map<int , int> hash;
    dfs(root, hash);
    
    int ans = -1;
    
    while(k--){
        ans = hash[node];
        node = hash[node];
    }
    
    return (ans == 0) ? -1 : ans;
}