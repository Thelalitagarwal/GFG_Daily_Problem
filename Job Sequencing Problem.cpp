class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        vector<int> ans(2,0);
        priority_queue<pair<int,int>>pq;
        int maxdeadl=-1;
        for(int i=0;i<n;i++){
            pair<int,int> p={arr[i].profit,arr[i].dead};
            maxdeadl= max(arr[i].dead,maxdeadl);
            pq.push(p);
        }
        
        vector<int>maxd(maxdeadl+1,-1);
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            for(int i=p.second;i>=1;i--){
                if(maxd[i]==-1){
                    ans[1]+=p.first;
                    ans[0]++;
                    maxd[i]=1;
                    break;
                }
            }
        }
        return ans;
    } 
};