class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*> ans;
        Node* start=head,*end=head;
        int n=s.length();
        
        // pattern string
        unordered_map<char,int> mp1;
        for(auto it:s) mp1[it]++;
        int count1=mp1.size();
        
        // traversing string
        unordered_map<char,int> mp2;
        int count2=0;
        while(end!=NULL)
        {
            mp2[end->data]++;
            if(mp1[end->data]==mp2[end->data]) count2++;
            
            while(mp2[end->data]>mp1[end->data])
            {
                if(mp2[start->data]==mp1[start->data]) count2--;
                mp2[start->data]--;
                start=start->next;
            }
        
            if(count2==count1)
            {
                ans.push_back(start);
                Node* ahead=end->next;
                end->next=NULL;
                start=ahead,end=ahead;
                mp2.clear();
                count2=0;
            }
            else
                end=end->next;
        }
        return ans;
    }
};