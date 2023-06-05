class Solution
{
    public:
	vector<int> pre;
	
	void preOrder(Node *root){
	    if(root==NULL) return;
	    
	    pre.push_back(root->data);
	    preOrder(root->left);
	    preOrder(root->right);
	}
	
    int minDiff(Node *root, int K)
    {
        //Your code here
        preOrder(root);
        int res = INT_MAX;
        
        for(auto x:pre){
            res = min(res, abs(K-x));
        }
        
        return res;
    }
};