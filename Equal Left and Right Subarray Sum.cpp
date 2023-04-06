class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        long long sum = accumulate(begin(A), end(A), 0);
        int ans = -1;
        long long leftsum = A[0];
        sum -= A[0];
        if(sum == 0)
            return 1;
        for(int i = 1; i < N - 1; i++){
            sum -= A[i];
            if(leftsum == sum){
                ans = i + 1;
                break;
            }
            leftsum += A[i];
        }
        return ans;
    }
};