class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<int> s;
        while(head1!=NULL)
        {
            s.insert(head1->data);
            head1=head1->next;
        }
        while(head2!=NULL)
        {
            s.insert(head2->data);
            head2=head2->next;
        }
        struct Node* ans = new Node(0);
        struct Node* temp=ans;
        for(auto it: s)
        {
            temp->next=new Node(it);
            temp=temp->next;
        }
        return ans->next;
    }
};