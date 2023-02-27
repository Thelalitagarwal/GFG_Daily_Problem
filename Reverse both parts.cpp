class Solution{
public:

    Node *reverse(Node *head, int k){

        int t = 0;
        Node* temp = head;
        Node* p = NULL;
        Node* q = head;
        Node* last;
        int flag = 1;
        while (temp -> next != NULL){

            p = temp;
            temp = temp -> next;
            p -> next = q;
            t++;
            q = p;
            if (t == k and flag == 1){
                last = p;
                flag = 0;
                p = NULL;
                q = NULL;
            }         
        }
        temp -> next = p;
        head -> next = temp;
        return last;
    }
};