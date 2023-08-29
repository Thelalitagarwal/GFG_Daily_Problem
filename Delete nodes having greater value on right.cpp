class Solution
{
    public:
    Node* Reverse(Node *head){
        Node* prev=NULL, *curr=head;
        while(curr){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        head=Reverse(head);
        Node* temp=head;
        while(temp){
            while(temp->next && temp->next->data<temp->data){
                temp->next=temp->next->next;
            }
            temp=temp->next;
        }
        head=Reverse(head);
        return head;
       
    }
    
};