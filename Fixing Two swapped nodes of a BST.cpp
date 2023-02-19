class Solution {
  public:
    int a,b;
    vector<int> ans;
    void inorder(struct Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->data);
        inorder(root->right);
        return;
    }
    void swap(struct Node* root){
        if(root==NULL){
            return;
        } 
        if(root->data == a){
            root->data = b;
        }
        else if(root->data == b){
            root->data = a;
        }
        swap(root->left);
        swap(root->right);
    }
    struct Node *correctBST(struct Node *root) {
        inorder(root);
        for(int i = 0; i < ans.size()-1; i++) {
            if (ans[i] > ans[i+1]) {
                a = ans[i];
                break;
            }
        }
        for(int i = ans.size()-1; i > 0; i--) {
            if (ans[i] < ans[i-1]) {
                b = ans[i];
                break;
            }
        }
        swap(root);
        return root;
    }
};