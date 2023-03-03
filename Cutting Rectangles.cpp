class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B){
        long long int K=__gcd(L,B);
        long long int N=L/K * B/K;
        return {N,K};
    }
};