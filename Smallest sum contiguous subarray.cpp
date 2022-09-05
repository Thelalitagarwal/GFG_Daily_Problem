class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      int sum = INT_MAX;
      int curSum = 0;
      for(int i=0;i<a.size();i++){
          curSum+=a[i];
          curSum = min(curSum, a[i]);
          sum = min(curSum,sum);
      }
      return sum;
  }
};
