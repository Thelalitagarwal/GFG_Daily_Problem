/*
Link to the "A difference of values and indexes" Problem ==>>  https://practice.geeksforgeeks.org/problems/a-difference-of-values-and-indexes0302/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/whirbaue-no 

*/

class Solution{
  public:
     int maxDistance(int arr[], int n){
        int mx1 = INT_MIN;
        int mn1 = INT_MAX;
        int mx2 = INT_MIN;
        int mn2 = INT_MAX;
        for(int i = 0; i < n; i++){
            mx1 = max(mx1, arr[i] - i);
            mn1 = min(mn1, arr[i] - i);
            mx2 = max(mx2, arr[i] + i);
            mn2 = min(mn2, arr[i] + i);
       } 
       return max((mx1-mn1),(mx2-mn2)); 
    } 
};
