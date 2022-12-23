/*
Link to the "Burst Balloons" Problem ==>>  https://practice.geeksforgeeks.org/problems/burst-balloons/1

Link to the complete Explaination Video ==>> https://youtu.be/mk1WOyAMay4 

*/

class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        
        int n = arr.size();
        vector<vector<int>>dp(n+2, vector<int>(n+1, 0));
        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        for(int i=n; i>= 1; i--){
            for(int j=1; j<=n; j++){
                if(i > j) 
                    continue;
                int maxi = INT_MIN;
                for(int k=i;k<=j;k++){
                    int ans = arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j];
                    if(maxi < ans) 
                        maxi = ans;
                }  
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};