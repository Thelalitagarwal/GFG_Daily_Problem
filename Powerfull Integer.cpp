class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        int maxi = 0;
        for(int i = 0;i < n;i++)
        {
            maxi = max(maxi,intervals[i][1]);
        }
        vector <int> ran(maxi + 2 , 0);
        for(int i = 0;i < n;i++)
        {
            ran[intervals[i][0]]++;
            ran[intervals[i][1] + 1]--;
        }
        int ele = -1;
        int oc = -1;
        int sum = 0;
        for(int i = 0;i < maxi + 2 ;i++)
        {
            sum += ran[i];
            if(sum >= k)
            {
                ele = i;
            }
        }
        return ele;
    }
};