class Solution {
  public:
    unsigned long long int noOfWays(unsigned long long int n){
        return (n*(n-1)+2);
    }
};