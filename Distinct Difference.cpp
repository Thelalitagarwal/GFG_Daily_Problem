/*
Link to the " Distinct Difference " Problem ==>>  https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/nvzxNppUIt0

*/

class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        unordered_set<int>st;
        vector<int>ans(N);
        for(int i=0;i<N;i++){
            ans[i]=st.size();
            st.insert(A[i]);
        }
        st.clear();
        for(int i=N-1;i>=0;i--){
            ans[i]-=st.size();
            st.insert(A[i]);
        }
        return ans;
    }
};