class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>>st;
        for(int i=0;i<N;i++){
            if(st.empty())  st.push(make_pair(color[i],radius[i]));
            
            else{
                if(st.top().first==color[i] && st.top().second==radius[i]){
                    st.pop();
                }
                else{
                    st.push(make_pair(color[i],radius[i]));
                }
            }
        }
        return st.size();
    }
};