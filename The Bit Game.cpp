class Solution{   
public:
    int swapBitGame(long long N){
        int cnt = 0;
        long long n = N;
        while(n > 0){
            if(n & 1) cnt++;
            n = n >> 1;
        }
        
        if(cnt & 1) return 1;
        return 2;
    }
};
