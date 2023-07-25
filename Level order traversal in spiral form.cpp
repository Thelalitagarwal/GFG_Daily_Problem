vector<int> findSpiral(Node *root){
    vector<int> ans;
    queue <Node*> pq;
    pq.push(root);
    int level = 0;
    while(!pq.empty()){
        int size = pq.size();
        vector<int> temp;
        for(int i = 0; i < size; i++){
            Node * node = pq.front();
            pq.pop();
            temp.push_back(node -> data);
            if(node -> left){
                pq.push(node -> left);
            }
            if(node -> right){
                pq.push(node -> right);
            }
        }
        if(level % 2 == 0){
            reverse(temp.begin(), temp.end());
        }
        for(auto i : temp){
            ans.push_back(i);
        }
        level++;
        
    }
    return ans;
}