
Link to the Problem: https://practice.geeksforgeeks.org/problems/5bfe93cc7f5a214bc6342709c78bc3dceba0f1c1/1

class Solution {
  public:
    int getMaximum(int N, vector<int> &arr) {
        long long sum = accumulate(arr.begin(),arr.end(),0ll);
        for(int i=N;i>=1;i--){
            if(sum%i==0)
            return i;
        }
    }
};
