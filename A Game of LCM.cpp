class Solution {
  public:
    long long gcd(long long A, long long B) {
        if (B == 0) return A;
        return gcd(B, A % B);
    }
    long long lcm(int N){
        if (N == 4) return 12;
        long long a = N * (N - 1);
        long long b = a;
        b *= (N - 2) / gcd(b, N - 2);
        b *= (N - 3) / gcd(b, N - 3);
        long long c = a, f = 0;
        for (int i = N - 2; i >= 1; i--) {
            if (gcd(c, i) == 1) {
                a *= i;
                c *= i;
                f++;
            }
            if (f == 2) break;
        }
        return max(a, b);
    }
    long long maxGcd(int N) {
        if(N==4)return 12;
        return max(lcm(N),lcm(N-1));
        
    }
};
