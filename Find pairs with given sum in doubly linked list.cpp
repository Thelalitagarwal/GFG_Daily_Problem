class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here 
        Node* last=head;
        while( last->next != NULL )
        {
            last =last->next ;
        }
        
        vector<pair<int,int>> ans ;
        while( head !=last )
        {
            int first = head->data ;
            int sec = last->data ;
            
            if( (first+sec) < target )
            {
                head = head->next ;
            }
            else if( (first+sec) > target )
            {
                last =last->prev ;
            }
            else 
            {
                ans.push_back( {head->data, last->data} ) ;
                head = head->next ; 
                if( head == last ) break ;
                last = last->prev ;
            }
        }
        
        return ans ;
        
    }
};