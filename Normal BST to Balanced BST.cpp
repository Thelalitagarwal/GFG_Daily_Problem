class Solution{
    public:
    void inorder(Node* root,vector<int> &vec){
        if(root==NULL)
        return;
        inorder(root->left,vec);
        vec.push_back(root->data);
        inorder(root->right,vec);
        
    }
    Node* buildTree(int vec[],int n){
        if(n==0)
        return NULL;
        Node* root=new Node(vec[n/2]);
        root->left=buildTree(vec,n/2);
        root->right=buildTree(vec+n/2,n/2);
        return root;
        
    }
    Node* buildBalancedTree(Node* root){
        vector<int> vec;
        inorder(root,vec);
        int arr[vec.size()];
        for(int i=0;i<vec.size();)arr[i]=vec[i++];
        Node* root1=buildTree(arr,vec.size());
        return root1;
    }
};