class Solution
{
  public:
  int maxWeightCell(int N, vector<int> arr)
  {
    vector<int> adj[N];
    for(int i = 0 ;i < N ; i++){
         if(arr[i] != -1)
         adj[arr[i]].push_back(i);
    }
    int val = 0;
    int ans = 0;
    for(int i = 0 ; i < N ; i++){
        int  sm  =0;
        for(auto x : adj[i]){
            sm = sm+x; 
        }
        if(sm >= val){
             val = sm;
             ans = i;
        }
    }
    return ans;
  }
};