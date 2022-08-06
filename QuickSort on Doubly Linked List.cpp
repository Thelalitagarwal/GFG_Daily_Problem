class Solution{
public:
    Node* partition(Node *l, Node *h){
        Node* pivot = l;
        Node *i = l, *j = h;
        bool flag = false;
        
        while(!flag) {
            while(i != NULL && i->data <= pivot->data){
                if(i == j) flag = true;
                i = i->next;
            }
            
            while(j != NULL && j->data > pivot->data){
                if(i == j) flag = true;
                j = j->prev;
            }
            
            if(!flag)
                swap(i->data,j->data);
        }
        
        if(flag){
            swap(pivot->data, j->data);
        }
        
        return j;
    }
};