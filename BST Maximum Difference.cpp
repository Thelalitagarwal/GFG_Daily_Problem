class Solution{
public:
    int maxdiff(Node *cur, int sum, int tempsum) {
        
        int l=INT_MIN, r=INT_MIN;
        if(cur->left) {
           l=maxdiff(cur->left,sum,tempsum+cur->data);
        }
        if(cur->right) {
           r=maxdiff(cur->right,sum,tempsum+cur->data);
        }
        if(!cur->left and !cur->right) {
            return sum-(tempsum+cur->data);
        }
        return max(l,r);
    }
    Node* findtarget(Node *cur, int target, int &sum) {
        
        if(cur==NULL) return NULL;
        
        sum+=cur->data;
        
        if(target<cur->data) {
           return findtarget(cur->left,target,sum);
        }
        else if(target>cur->data) {
           return findtarget(cur->right,target,sum);
        }
        else {
            return cur;
        }
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int sum=0;
        Node* ans=findtarget(root,target,sum);
        if(ans==NULL) return -1;
        return maxdiff(ans,sum,0);
    }
};
