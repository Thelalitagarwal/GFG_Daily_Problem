class Solution {
  public:

    long long maxGcd(long long N) {
        long long a = N * (N - 1);
        long long b = a;
        b *= (N - 2) /__gcd(a,N-2);
        b *= (N - 3) /__gcd(a,N-3);
        int f = 0;
        for (long long i = N - 2; i >= 1; i--) {
            if (__gcd(a, i) == 1) {
                a *= i;
                f++;
            }
            if (f == 2) break;
        }
        return max(a, b);
    }
};