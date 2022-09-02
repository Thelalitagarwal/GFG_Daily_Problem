class Solution {
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n){
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        int i=0, j=0;
        int ans=0;
        
        while(i<x.size() and j<y.size()){
            if(x[i]>y[j]){
                ans+=(j+1)*x[i];
                i++;
            }
            else{
                ans+=(i+1)*y[j];
                j++;
            }
        }
        
        while(i<x.size()){
            ans+=(j+1)*x[i];
            i++;
        }
        
        while(j<y.size()){
            ans+=(i+1)*y[j];
            j++;
        }
        return ans;
    }
};
