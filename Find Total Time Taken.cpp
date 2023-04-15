class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        // code here
        unordered_map<int,int>mp;
        int timec=0;
        for(int i=0;i<n;i++)
        {  
            if(mp.find(arr[i])!=mp.end()){
                int temp=(time[arr[i]-1]-(timec-mp[arr[i]]));
                if(temp>0)timec+=temp;
            }
            mp[arr[i]]=timec;
            timec++;  
        }
      
        return timec-1;
    }
};