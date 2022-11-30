class Solution{ 
    private:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* temp=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    Node* getmid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
public:

    void reorderList(Node* head) {
        Node* l1 = head;
        Node* mid = getmid(head);
        Node* l2 = mid->next;
        mid->next=NULL;
        l2 = reverse(l2);
        Node* ans=new Node(-1);
        Node* curr=ans;
        while(l1 || l2){
            if(l1){
                curr->next=l1;
                curr=curr->next;
                l1=l1->next;
            }
            if(l2){
                curr->next=l2;
                curr=curr->next;
                l2=l2->next;
            }
        }
        head = ans->next;
    }
};
