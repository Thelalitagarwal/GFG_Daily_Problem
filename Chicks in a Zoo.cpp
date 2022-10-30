class Solution {
public:
	 long long int NoOfChicks(int n){
     long long int chicks[n + 1];
     chicks[0] = 0;
     chicks[1] = 1;
     int pre = 0;
     long long int sum = 1;
     for(int i = 2; i <= n; i++){
         if(i >= 6) sum -= chicks[pre++];
         chicks[i] = sum * 2;
         sum += chicks[i];
     }
     return sum;
 }
};