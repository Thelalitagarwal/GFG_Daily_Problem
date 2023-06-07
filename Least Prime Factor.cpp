class Solution {
  public:
    vector<int> leastPrimeFactor(int n) { 
        vector<int> least_prime(n+1, 0); 
        least_prime[1] = 1; 
        for (int i = 2; i <= n; i++) { 
            if (least_prime[i] == 0) {  
                least_prime[i] = i; 
                for (int j = 2*i; j <= n; j += i) 
                    if (least_prime[j] == 0) 
                       least_prime[j] = i; 
            } 
        } 
        return least_prime;
    }
};