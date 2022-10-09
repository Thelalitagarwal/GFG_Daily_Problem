class Solution {
	bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
	public:
		int NthTerm(int N){
		   if(N==1){
		        return 1;
		    }
		   int ans=INT_MAX;
		   for(int i=N;i>0;i--){
		       if(isPrime(i)){
		           ans=min(ans,N-i);
		           break;
		       }
		   }
		   
		   for(int i=N;i<=100000;i++){
		       if(isPrime(i)){
		           ans=min(ans,i-N);
		           break;
		       }
		   }
		   return ans;
		}
};