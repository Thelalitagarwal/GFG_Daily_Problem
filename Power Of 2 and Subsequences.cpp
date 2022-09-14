class Solution{   
public:
    long long numberOfSubsequences(int N, long long A[]){
        int cnt = 0;
        
        for(int i = 0;i<N;i++)
            if(floor(log2(A[i])) == ceil(log2(A[i]))) 
                cnt++;
        
        long long mod = 1e9 + 7;
        long long temp =1;
        while(cnt)
        {
            temp = (temp%mod * 2)%mod;
            cnt--;
        }
        return (temp%mod - 1)%mod;
    }
};