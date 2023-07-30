class Solution{
  public:
    Node * inOrderSuccessor(Node *root, Node *x){  
    Node* ans;
    while(root){
        if(root->data <= x->data){
            root = root->right;
        }
        else if(root->data > x->data){
            ans = root;
            root = root->left;
        }
    }
    return ans;
}
};