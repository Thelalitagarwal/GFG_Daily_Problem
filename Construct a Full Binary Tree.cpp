Link To the Problem: https://practice.geeksforgeeks.org/problems/93c977e771fc0d82e87ba570702732edb2226ad7/1

class Solution{
  public:
    Node* helper(int ps, int pe, int pre[], int pms, int pme, int preMirror[]){
        if(ps>pe || pms>pme) return NULL;
        
        Node* newNode=new Node(pre[ps]);
        
        if(ps==pe) return newNode;
        int i,j;
        for(i=ps; i<=pe; ++i){
            if(pre[i]==preMirror[pms+1]) break;
        }
        for(j=pms; j<=pme; ++j){
            if(preMirror[j]==pre[ps+1]) break;
        }
        newNode->left=helper(ps+1, i-1, pre, j, pme, preMirror);
        newNode->right=helper(i, pe, pre, pms+1, j-1, preMirror);
        return newNode;
    }


    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        int ps=0, pe=size-1, pms=0, pme=size-1;
        return helper(ps, pe, pre, pms, pme, preMirror);
    }
};
