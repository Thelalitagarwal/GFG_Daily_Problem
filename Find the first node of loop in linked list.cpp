/*
Link to the "Find the first node of loop in linked list" Problem ==>> https://practice.geeksforgeeks.org/problems/44bb5287b98797782162ffe3d2201621f6343a4b/1

Link to the complete Explaination Video ==>> https://youtu.be/-kU7QNrQoUo 

*/

class Solution
{
    public:
    int findFirstNode(Node* head){
         Node*slow=head;
        Node*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
        if(fast!=slow) 
            return -1;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
       return slow->data;
    }
};