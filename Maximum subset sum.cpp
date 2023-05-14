class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<long long> prev(2), cur(2);
        prev[0] = 0;
        prev[1] = A[0];
        
        for(int i=1; i<N; i++){
            cur[1] = A[i] + max(prev[0], prev[1]);
            cur[0] = prev[1];
            
            prev = cur;
        }
        return max(prev[0], prev[1]);
    }
};