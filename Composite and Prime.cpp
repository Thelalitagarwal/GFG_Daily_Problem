class Solution {
	public:
        bool isPrime(int N){
           for(int i=2;i<=sqrt(N);i++){
               if(N%i==0){
                   return false;
               }
           }
          return true;
        }
        
		int Count(int L, int R){
		    int x = 0, y = 0;
		    for(int i=L; i<=R; ++i) {
		        if(i==1){
		            continue;
		        }
		        else if(isPrime(i))
		            x++;
		      else{
		          y++;
		      }
		    }
            return (y-x);
		}
};