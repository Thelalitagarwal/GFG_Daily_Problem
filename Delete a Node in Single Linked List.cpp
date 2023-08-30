Node* deleteNode(Node *head,int x){
    if(x==1){
        head=head->next;
    }
    else{
        Node*curr=head;
        for(int i=0;i<x-2;i++){
            curr=curr->next;
        }   
        curr->next=curr->next->next;
    }
    return head;
}