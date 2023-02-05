class Solution
{
public:
      int intersectPoint(Node* head1, Node* head2){
        int l1 = 0, l2 = 0;
        Node *h1 = head1, *h2 = head2;
        while(h1) {
            l1++;
            h1 = h1->next;
        }
        while(h2) {
            l2++;
            h2 = h2->next;
        }
        h1 = head1, h2 = head2;
        if(l1 > l2) {
            for(int i = 0; i < l1 - l2; i++)
                h1 = h1->next;
        } 
        else {
            for(int i = 0; i < l2 - l1; i++)
                h2 = h2->next;
        }
        while(h1 != h2) {
            h1 = h1->next;
            h2 = h2->next;
        }
        return h1->data;
    }
};