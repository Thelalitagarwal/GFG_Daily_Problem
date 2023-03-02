class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();
        if(k == 1 && n > 1) return -1;
        else if(k == 0 || n == 0)   return -1;
        int first = INT_MAX, sec = INT_MAX;
        for(int i = 0; i < k; i++){
            if(costs[0][i] < first){
                sec = first;
                first = costs[0][i];
            }
            else if(costs[0][i] < sec)
                sec = costs[0][i];
        }
        for(int i = 1; i < n; i++){
            int firall = INT_MAX, secall = INT_MAX;
            for(int j = 0; j < k; j++){
                if(costs[i - 1][j] == first)
                    costs[i][j] += sec;
                else
                    costs[i][j] += first;
                    
                if(costs[i][j] < firall){
                    secall = firall;
                    firall = costs[i][j];
                }
                else if(costs[i][j] < secall)
                    secall = costs[i][j];
            }
            first = firall;
            sec = secall;
        }
        return first;
    }
};