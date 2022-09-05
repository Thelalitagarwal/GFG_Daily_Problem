class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      int sum = INT_MAX, curSum = 0, minSum = INT_MAX;
      for(int i=0;i<a.size();i++){
          curSum+=a[i];
          curSum = min(curSum, a[i]);
          sum = min(curSum,sum);
          minSum = min(minSum, sum);
      }
      
      return minSum;
  }
};