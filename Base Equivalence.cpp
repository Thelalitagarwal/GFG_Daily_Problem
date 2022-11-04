class Solution {
  public:
     string baseEquiv(int n, int m){
        int i=2;
        while(i<=32){
            if((int(log(n)/log(i))+1)==m){
                return "Yes";
            }
            i++;
        }
        return "No";
    }
};