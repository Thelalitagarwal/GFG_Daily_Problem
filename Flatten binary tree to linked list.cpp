class Solution {
       public:
           void flatten(Node* root) 
           {
               Node* cur = root;
		       
		       while (cur){
		           
		           if(cur->left){
		               
		               Node* pre = cur->left;
		               
            		   while(pre->right){
            			   pre = pre->right;
            		   }
            		   pre->right = cur->right;
            		   
            		   cur->right = cur->left;
            		   
            		   cur->left = NULL;
			        }
			       cur = cur->right;
			       
		        }
            }
  };