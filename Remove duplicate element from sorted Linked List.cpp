Node *removeDuplicates(Node *head)

{

 // your code goes here 

 Node *t=head;

 while(t->next){

     if(t->data==t->next->data){

         t->next=t->next->next;

     }else{

     t=t->next;

     }

 }return head;

}