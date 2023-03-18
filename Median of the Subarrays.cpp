/*
Link to the " Median of the Subarrays " Problem ==>>  https://practice.geeksforgeeks.org/problems/6f08220ca3b871be594f50f7f56a9ef2799cb485/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/CPKVt3r-eTQ

*/

class Solution 
{
  public:
    long long solve(int n, vector<int>& A, int m) {
        
        vector<int> mp(2*n+1, 0);
        long long cur = n, tot = 0, ans = 0;
        mp[cur]++;
        for (int i = 0; i < n; i++) {
            if (A[i] >= m) {
                tot += mp[cur];
                cur += 1;
            }
            else{
                tot -= mp[cur-1];
                cur -= 1;
            }
            ans += tot;
            mp[cur]++;
        }
        return ans;
    }
    
    long long countSubarray(int N, vector<int> A, int M){
        
        return solve(N, A, M) - solve(N, A, M+1);
    }
};