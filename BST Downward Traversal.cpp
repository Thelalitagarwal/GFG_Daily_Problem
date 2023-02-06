class Solution{
    public:
    long long int verticallyDownBST(Node *root,int target){
        queue<Node*> q;
        q.push(root);
        long long ans=0;
        Node* tar=NULL;
        while(!q.empty()){
                Node* node=q.front();
                q.pop();
                if(node->data==target){
                    tar=node;
                    break;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
        }
        if(tar==NULL) return -1;
        queue<pair<Node*,int>> x;
        if(tar->left){
            x.push({tar->left,-1});
        }
        if(tar->right){
            x.push({tar->right,+1});
        }
        while(!x.empty()){
            auto it=x.front();
            x.pop();
            Node *node=it.first;
            int level=it.second;
            if(level==0){
                ans+=node->data;
            }
            if(node->left){
                x.push({node->left,level-1});
            }
            if(node->right){
                x.push({node->right,level+1});
            }
        }
        return ans;
    }
};