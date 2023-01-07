/*
Link to the "Flattening a Linked List" Problem ==>>  https://practice.geeksforgeeks.org/problems/da62a798bca208c7a678c133569c3dc7f5b73500/1

Link to the complete Explaination Video ==>> https://youtu.be/Ua5othsS8A0 

*/

class Solution {
public:
    Node *flatten(Node *root){
        
         Node* line= root->next;
         while(line!=NULL){
              Node* t=line;
              Node* p=root;
              Node* p_pre=NULL;
            while(t!=NULL&&p!=NULL){
                if(p->data>=t->data&&p==root){
                       p_pre=t;
                      t=t->bottom;
                      p_pre->bottom=p;
                      root=p_pre;
                  }
                else if(p->data>=t->data){
                     p_pre->bottom=t;
                    t=t->bottom;
                    p_pre=p_pre->bottom;
                    p_pre->bottom=p;
                }
                else{
                    p_pre=p;
                    p=p->bottom;
                }
           }
           if(p==NULL&&t!=NULL)
              p_pre->bottom=t;
            
           line=line->next;
       }
      return root;  
    }
};