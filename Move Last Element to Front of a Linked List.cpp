class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head->next==NULL) return head; 
        ListNode* last=head->next, *slast=head;
        while(last->next){
            last=last->next;
            slast=slast->next;
        }
        slast->next=NULL;
        last->next=head;
        return last;
    }
};