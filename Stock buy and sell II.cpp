class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int maxi = 0, mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (prices[i] > mini)
                maxi += prices[i] - mini;
            mini = prices[i];
        }
        return maxi;
    }
};