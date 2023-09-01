void printCorner(Node *root)
{
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> tmp;
        while(n--){
            auto b = q.front();q.pop();
            tmp.push_back(b->data);
            if(b->left) q.push(b->left);
            if(b->right) q.push(b->right);
        }
        if(tmp.size() == 1) cout<<tmp[0]<<" ";
        else cout<<tmp[0]<<" "<<tmp[tmp.size()-1]<<" ";
    }
}