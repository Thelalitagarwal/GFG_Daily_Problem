class Solution{
public:
    typedef pair<long long, long long> pll;
    pll minmax(long long pre[], int l, int r) {
        int lo = l, hi = r-1;
        long long minSum = 0, maxSum = pre[r] - pre[l-1];
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long lsum = pre[mid] - pre[l-1], rsum = pre[r] - pre[mid];
            if(abs(rsum - lsum) < maxSum - minSum) {
                minSum = min(lsum, rsum);
                maxSum = max(lsum, rsum);
            }
            if(lsum < rsum) lo = mid + 1;
            else hi = mid - 1;
        }
        return {minSum, maxSum};
    }
    long long minDifference(int N, vector<int> &A) {
        long long presum[N+1];
        presum[0] = 0;
        for(int i = 1; i <= N; i++) presum[i] = presum[i-1] + A[i-1];
        long long ans = presum[N];
        for(int i = 1; i < N-2; i++) {
            pll mml = minmax(presum, 1, i+1), mmr = minmax(presum, i+2, N);
            ans = min(ans, max(mml.second, mmr.second) - min(mml.first, mmr.first));
        }
        return ans;
    }
};