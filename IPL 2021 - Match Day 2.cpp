class Solution {
    public:
     vector<int> max_of_subarrays(vector<int> a, int n, int k) {
        vector<int>ans;
        deque<int>q;
        int i=0, j=0;
        while(j<a.size())
        {
            while(q.size() && q.back()<a[j])
            q.pop_back();
            q.push_back(a[j]);
            if(j-i+1<k)
            j++;
            else
            {
                ans.push_back(q.front());
                if(q.front()==a[i])
                q.pop_front();
                i++; 
                j++;
            }
        }
        return ans;
    }
};