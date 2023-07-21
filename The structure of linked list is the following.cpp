//Code
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_map<int,int>ump;
        Node *temp = head;
        Node *node = new Node(-1);
        Node *ans = node;
        while(temp!=NULL)
        {
            if(ump[temp->data]==0){
                node->next = new Node(temp->data);
                node = node->next;
                ump[temp->data]++;
            }
            temp = temp->next;
        }
        return ans->next;
    }
};
