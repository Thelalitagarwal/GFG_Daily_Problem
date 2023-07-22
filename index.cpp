/*

*/

//code
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    void totalr(struct node *&cur ,struct node *&cur1 ,struct node *&prev,int &round,struct node* &head){
        // cout<<"calling helper"<<endl;
        // cout<<cur->data<<" "<<cur1->data<<endl;
        // if(prev!=NULL)cout<<prev->data<<endl;
        node *newcur=cur1->next;
        node *p1=newcur;
        node *prev1=prev;
        if(round==0){
            head=cur1;
        }
        prev=cur;
        while(cur!=cur1){
            node *next1=cur->next;
            cur->next=p1;
            p1=cur;
            cur=next1;
        }
        cur->next=p1;
        if(prev1!=NULL){
            prev1->next=cur;
        }
        cur=newcur;
    }
    struct node *reverse (struct node *head, int k)
    {
        node *cur=head;
        node *prev=NULL;
        int round=0;
        while(true){
            node* cur1=cur;
            int count=1;
            bool outofbeyond=false;
            while(cur1->next!=NULL && count<k){
                if(cur1->next==NULL){
                    break;
                }
                cur1=cur1->next;
                count++;
            }
            totalr(cur,cur1,prev,round,head);
            
            if(cur1->next==NULL || cur==NULL){
                outofbeyond=true;
            }
            round++;
            if(outofbeyond==true){
                break;
            }
        }
        return head;
    }
};
