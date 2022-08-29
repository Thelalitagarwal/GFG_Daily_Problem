class Solution
{
public:
    Node *nextRight(Node *root, int key)
   {
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int sz=q.size();
           for(int i=0;i<sz;i++){
               Node *temp=q.front();
               q.pop();
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
               if(i!=sz-1 && temp->data==key){
                   return q.front();
               }
           }
       }
       return new Node(-1);
   }
};