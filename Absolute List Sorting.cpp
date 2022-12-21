/*
Link to the "Absolute List Sorting" Problem ==>>  https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1

Link to the complete Explaination Video ==>> https://youtu.be/_x0J4Dls-qw 

*/

class Solution{
public:
     Node* sortList(Node* head){
         
        if(!head || !(head->next))
            return head;
        
        Node *current=head->next;
        Node *previous=head;
        Node *front=head;
        
        while(current){
            if((current->data)<0){
                while(current && (current->data)<0){ 
                    previous->next=current->next;
                    current->next=front;
                    front=current;
                    current=previous->next;
                }
            }
            if(current){
                current=current->next;
                previous=previous->next;
            }
        }
        return front;
    }
};