class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        long long int sum=0;
        for(auto it:A){
             sum+=it;
        }
        int ans=INT_MAX;
        for(int i=0;i<N;i++){
            if((long long)N*A[i]>=sum){
               ans=min(ans,A[i]);  
            }
        }
        return ans;
    }
};