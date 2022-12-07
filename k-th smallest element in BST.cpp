/* 

Link to the "Distance of nearest cell having 1" Problem ==>>  https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/8waTdK0iTls 
   
*/

class Solution {
  public:
    int  ans = -1;
    void inorder(Node *r,int &k){
        if(r == NULL)
        return;
        inorder(r->left,k);
        k--;
        if(k == 0){
            ans = r->data;
        }
        inorder(r->right,k);
    }
    int KthSmallestElement(Node *root, int K) {
        inorder(root,K);
        return ans;
    }
};