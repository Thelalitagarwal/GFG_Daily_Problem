#define TreeNode Node

class Solution {
public:
    int mini = INT_MAX;
    
    bool checkBST(TreeNode *root, int minVal, int maxVal){
        if (root == NULL){
            return true;
        }
        if (root->data < minVal || root->data > maxVal){
            return false;
        }
        return checkBST(root->left, minVal, root->data-1) && checkBST(root->right, root->data+1, maxVal);
    }

    int sum(TreeNode *root,int &count){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            count++;
            return root->data;
        }
        count++;
        return root->data+sum(root->left,count)+sum(root->right,count);
    }
    
    void solve(TreeNode *root,int target){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            if(root->data==target){
                mini=1;
                return ;
            }
        }
        if(checkBST(root, INT_MIN, INT_MAX)){
            int count=0;
            int s=sum(root,count);
            if(s==target){
                mini=min(mini,count);
            }
        }
        solve(root->left,target);
        solve(root->right,target);
    }
    
    int minSubtreeSumBST(int target, Node *root) {
        solve(root,target);
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};