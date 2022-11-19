class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        queue<Node*>q1,q2;
        q1.push(root1);
        q2.push(root2);
        while(1){
           int size1=q1.size();
            int size2=q2.size();
           if(size1!=size2) return false;
           if(size1==0) break;
           vector<int>level_tree1,level_tree2;
           while(size1--){
                Node* node1 = q1.front();
                q1.pop();
                if(node1->left!=NULL) q1.push(node1->left);
                if(node1->right!=NULL) q1.push(node1->right);
                level_tree1.push_back(node1->data);
                 Node* node2 = q2.front();
                q2.pop();
                if(node2->left!=NULL) q2.push(node2->left);
                if(node2->right!=NULL) q2.push(node2->right);
                level_tree2.push_back(node2->data);
            }
            sort(level_tree1.begin(),level_tree1.end());
            sort(level_tree2.begin(),level_tree2.end());
            if(level_tree1 != level_tree2)
                return false;
        }
            return true;
    }
};