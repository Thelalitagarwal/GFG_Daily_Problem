class Solution {
    public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        long long preSum = 0;
        queue<long long> q;
        for (auto num : GeekNum) {
            q.push(num);
            preSum += num;
        }
        if (N <= K) return GeekNum[N - 1];
        long long curr = preSum;
        for (int i = K; i < N; ++i){
            curr = preSum;
            q.push(curr);
            preSum += curr;
            preSum -= q.front();
            q.pop();
        }
        return curr;
    }
};