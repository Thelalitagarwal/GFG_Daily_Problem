class Solution{
public:
    int xmod11(string x){
      int n = x.size();
      int sum = 0;
      for(int i = 0; i<n;i++){
          sum = (sum * 10 + (x[i] - '0')) % 11;
      }
      return sum;
    }
};