class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        long long ans = 0;
         sort(arr.begin(), arr.end());
         for(int i = 1; i < N; i++){
            if(arr[i] <= arr[i-1]){
                int diff=arr[i-1]-arr[i];
                ans+=diff+1;
                arr[i]+=diff+1;
            }
         }
         return ans;
    }
};