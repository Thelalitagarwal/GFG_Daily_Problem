class Solution
{
    public: 
    Node* prev=NULL;
    Node* head=NULL;
    Node * bToDLL(Node *root){
        if(root==NULL)
        return NULL;
        bToDLL(root->left);
        if(prev==NULL)
        head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        bToDLL(root->right);
        return head;
    }
};