/*
Link to the "Absolute difference divisible by K" Problem ==>>  https://practice.geeksforgeeks.org/problems/e0059183c88ab680b2f73f7d809fb8056fe9dc43/1

Link to the complete Explaination Video ==>> https://youtu.be/HJd6iV19zPs 

*/

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        
        long long ans = 0;
        int mp[k+1]={0};
        for(int i=0;i<n;i++){
            ans += mp[arr[i]%k];
            mp[arr[i]%k]++;
        }
        return ans;
    }
};