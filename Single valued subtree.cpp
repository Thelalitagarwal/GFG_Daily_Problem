class Solution{
   public:
    int ans=0;
    pair<bool,int> subtree(Node* root){
        if(!root){
            return {true,INT_MAX};
        }
        pair<bool,int>left=subtree(root->left);
        pair<bool,int>right=subtree(root->right);
        
        if(left.first && right.first){
            if((root->data==left.second || left.second==INT_MAX) && (root->data==right.second || right.second==INT_MAX)){
                 ans++;
                 return {true,root->data};
            }
        }
        return {false,root->data};
    }
    int singlevalued(Node *root){
        pair<bool,int> temp=subtree(root);
        return ans;
    }
    
};