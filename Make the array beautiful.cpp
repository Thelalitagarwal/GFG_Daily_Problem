class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        
        stack<int>st; 
        for(auto it: arr){
            if(st.size()==0){
                st.push(it);
            }
            else{
                if((st.top()>=0 and it<0) || (st.top()<0 and it>=0))st.pop();
                else st.push(it);
            }
        }
        vector<int>ans; 
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};