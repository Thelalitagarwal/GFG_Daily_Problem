class Solution {
  public:
    int safePos(int n, int k){
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