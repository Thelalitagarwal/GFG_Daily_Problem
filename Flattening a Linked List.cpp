/*
Link to the "Flattening a Linked List" Problem ==>>  https://practice.geeksforgeeks.org/problems/da62a798bca208c7a678c133569c3dc7f5b73500/1

Link to the complete Explaination Video ==>> https://youtu.be/Ua5othsS8A0 

*/

class Solution {
public:
     Node* merge(Node* a, Node* b){
        Node* dummy= new Node(-1);
        Node* curr=dummy;
        while(a && b){
            if(a->data<=b->data){
                curr->bottom= new Node(a->data);
                curr=curr->bottom;
                a=a->bottom;
            }
            else{
                curr->bottom= new Node(b->data);
                curr=curr->bottom;
                b=b->bottom;
            }
        }
        if(a) curr->bottom=a;
        if(b) curr->bottom=b;
        
        return dummy->bottom;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        if(!root->next) return root;
        Node* ans= merge(root, flatten(root->next));
        return ans;
    }
};
