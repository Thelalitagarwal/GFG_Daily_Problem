class Solution{
 public:
   int turn(Node*root,int n,char sign)
   {
       if(root==nullptr) return INT_MAX-1;
       if(root->data==n) return 0;
       
       int h1=0,h2=0;
       if(sign=='L')
       {
         h1=turn(root->left,n,'L');
         h2=1+turn(root->right,n,'R');
       }
       else if(sign=='R') //Do same as above;
       {
           h1=1+turn(root->left,n,'L');
           h2=turn(root->right,n,'R');
       }
       return min(h1,h2);
   }
   Node* lca(Node* root ,int n1 ,int n2)
   {
      if(root==nullptr){
        return nullptr;
      }
      
      if(root->data==n1|| root->data==n2){
          return root;
      }
      
      Node* h1= lca(root->left,n1,n2);
      Node* h2= lca(root->right,n1,n2);
      
      if(h1==nullptr)
       return h2;
      if(h2==nullptr) 
        return h1;
      
      if((h1->data==n1 || h2->data==n2) || (h1->data==n2 || h2->data==n1))
        return root;
   }
   
   
   int NumberOFTurns(struct Node* root, int first, int second)
   {
     Node* lc=lca(root,first,second);
     
     int turn1=min(turn(lc,first,'L'),turn(lc,first,'R'));
     int turn2=min(turn(lc,second,'L'),turn(lc,second,'R'));
     
     if(turn1+turn2==0 && (lc->data==first || lc->data==second)) return -1;
     
      if((lc->data==first || lc->data==second)) return turn1+turn2;
      
      return turn1+turn2+1; 
   }
};