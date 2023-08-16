class Solution{
    public:
    int findCatalan(int n) {
        if (n == 0) {
            return 1;
        } 
        const int MOD = 1e9 + 7;
        vector<long long> v(n + 1, 0);
        v[0] = v[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                v[i] = (v[i] + (v[j] * v[i - j - 1]) % MOD) % MOD;
            }
        } 
        return static_cast<int>(v[n]);
    }
};