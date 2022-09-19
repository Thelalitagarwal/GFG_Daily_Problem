class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        stack<int> s;
        vector<int> ans;
        ans.push_back(-1); 
        s.push(arr[0]);
        for(int i=1;i<n;++i){
            if(arr[i]>s.top()){
                ans.push_back(s.top());
                s.push(arr[i]);
            }
            else if(arr[i]<=s.top()){
                while(!s.empty() and arr[i]<=s.top()){
                    s.pop();
                }
                if(!s.empty()){
                    ans.push_back(s.top());
                    s.push(arr[i]);
                }
                else{
                    ans.push_back(-1);
                    s.push(arr[i]);
                }
            }
        }
        return ans;
    }
};