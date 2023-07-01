class Solution {
  public:
    int setBits(int N) {
        int count = 0;
        while(N) {
            int last_digit = (N&1); 
            count += last_digit;  
            N = N >> 1;
        }
        
        return count;
    }
};