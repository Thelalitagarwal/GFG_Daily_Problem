class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<long long int> prev(sum + 1, 0);
        for (int i = 0; i <= sum; i++) {
            if (i % coins[0] == 0) {
                prev[i] = 1;
            }
        }
        for (int i = 1; i < N; i++) {
            vector<long long int> curr(sum + 1, 0);
            for (int j = 0; j <= sum; j++) {
                long long int a, b;
                a = b = 0;
                a = prev[j];
                if (j >= coins[i]) {
                    b = curr[j - coins[i]];
                }
                curr[j] = a + b;
            }
            prev = curr;
        }
        return prev[sum];
    }
};