class Solution{
  public:
    void InOrder(vector<int> &vec,Node *root){
        if(root){
            InOrder(vec,root->left);
            vec.push_back(root->data);
            InOrder(vec,root->right);
        }
    }
    
    void postOrderConvert(vector<int> &vec,Node* root,int &i){
        if(root){
            postOrderConvert(vec,root->left,i);
            postOrderConvert(vec,root->right,i);
            root->data=vec[i++];
        }
    }
  
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> vec;
        InOrder(vec,root);
        int ind=0;
        postOrderConvert(vec,root,ind);
    }       
};