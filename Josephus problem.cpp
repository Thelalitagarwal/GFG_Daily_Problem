
// Naive Approach

class Solution
{
    public:
    int josephus(int n, int k)
    {
        list<int>l;
        for(int i=0;i<n;i++) 
        l.push_back(i+1);
       
        auto it=l.begin();
        while(l.size()>1){
           for(int count=1;count<k;count++){
               it++;
               if(it==l.end())it=l.begin();
           }
            it=l.erase(it);
            if(it==l.end())it=l.begin();
        }
       return *l.begin();
    }
};


// Efficient Approach 

class Solution
{
    public:
    int josephus(int n, int k)
    {
        if (n == 1)
        return 1;
      else
        return (josephus(n - 1, k) + k-1) % n + 1;
    }
};
