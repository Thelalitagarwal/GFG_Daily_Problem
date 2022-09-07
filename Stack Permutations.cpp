class Solution{
public:
    int isStackPermutation(int n,vector<int> &A,vector<int> &B){
        int i = 0, j = 0;
        stack<int> st;
        
        while(j < n){
            
            while(i<n && (st.empty() || st.top() != B[j]))
            {
                st.push(A[i++]);
            }
            
            if(!st.empty() && st.top() == B[j]){
                st.pop();
                j++;
            }  
            else return 0;
        }
        
        return 1;
    }
};