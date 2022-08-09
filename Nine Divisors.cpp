class Solution{   
public:
    long long int nineDivisors(long long int N) {
        long long int c = 0; 
        long long int limit = sqrt(N); 
        long long int prime[(int)limit + 1]; 
        
        for (int i = 1; i <= limit; i++) 
            prime[i] = i; 
        
        for (int i = 2; i * i <= limit; i++) { 
            if (prime[i] == i) { 
                for (int j = i * i; j <= limit; j += i) 
                    if (prime[j] == j) 
                        prime[j] = i; 
            } 
        } 
        for (int i = 2; i <= limit; i++) { 
            long long int p = prime[i]; 
            long long int q = prime[(int)i / prime[i]]; 
            if (p * q == i && q != 1 && p != q) { 
                c += 1; 
            } 
            else if (prime[i] == i) { 
                if (pow(i, 8) <= N) { 
        
                    c += 1; 
                } 
            } 
        } 
        
        return c; 
    }
};
