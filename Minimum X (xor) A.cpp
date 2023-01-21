/*
Link to the "Minimum X (xor) A" Problem ==>> https://practice.geeksforgeeks.org/problems/1fc4278adf2a36780f637c7b4cd06391dd1487e4/1

Link to the complete Explaination Video ==>> https://youtu.be/ntenHejBcCA 

*/


class Solution {
  public:
     int minVal(int a, int b) {
         
        int tempb=b;
        int bsetbits=0;
        while(tempb>0){
            if(tempb&1) bsetbits++;
            tempb>>=1;
        }
        int tempa=a;
        int asetbits=0;
        while(tempa>0){
            if(tempa&1) asetbits++;
            tempa>>=1;
        }
        if(asetbits==bsetbits){
            return a;
        }
        else if(asetbits>bsetbits){
            int ans=0;
            int rem=bsetbits;
            for(int i=31;i>=0;i--){
                if(a&(1<<i)){
                    ans|=(1<<i);
                    rem--;
                } 
                if(rem==0)
                    return ans;
            }
        }
        else{
            int rem=bsetbits-asetbits;
            int ans=a;
            for(int i=0;i<=31;i++){
                if((a&(1<<i))==0){
                    ans|=(1<<i);
                    rem--;
                } 
                if(rem==0) return ans;
            }
        }
        return 0;
    }
};