/*
Link to the "Next Greater Element" Problem ==>> https://practice.geeksforgeeks.org/problems/214734e358208c1c6811d9b237b518f6b3c3c094/1

Link to the complete Explaination Video ==>> https://youtu.be/tl2D8rNKJOE 

*/

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n, -1);
        stack<long long> st;
        st.push(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }   
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};