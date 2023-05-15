class Solution {
  public:
    long long countBits(long long N) {
        // code here
        long long sum=0;
        for(int i=1;i<=N;i++){
            sum+=__builtin_popcount(i);
        }
        return sum;
    }
};
