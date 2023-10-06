class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        if(odd->next == NULL || odd->next->next == NULL) return;
        Node *curr = odd;
        int cnt = 1;
        while(curr->next){
            curr = curr->next;
            cnt++;
        }
       Node *first = odd;
       Node *prev = NULL;
       Node *second = first->next;
       while(first->next != NULL && second->next != NULL){
           first->next = second->next;
           first = second->next;
           second->next = prev;
           prev = second;
           second = first->next;
       }
      if(cnt%2 == 0){
      second->next = prev;
      }
      else{
          first->next = prev;
      }
    }
};
