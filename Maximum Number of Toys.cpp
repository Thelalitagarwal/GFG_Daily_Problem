class Solution {
public:
     int solve(vector<int>& Queries ,vector<long long>&sum,vector<vector<int>>& arr,unordered_map<int,int>&new_ind){
    long long val = Queries[0];
    int cnt = 0;
    int s = 0;
    int e = sum.size()-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(sum[mid]<=val){
            cnt = mid + 1;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    int ans = 0;
    unordered_set<int> st;
    long long cur_sum = val - sum[cnt-1];
    for(int i=2;i<Queries.size();i++){
        if(new_ind[Queries[i]]<=cnt){
            cur_sum+=arr[new_ind[Queries[i]]-1][0];
            ans--;
        } 
        st.insert(new_ind[Queries[i]]);
    }
    for(int i=cnt;i<arr.size();i++){
        if(arr[i][0]>cur_sum) break;
        if(st.count(i+1)) continue;
        ans++;
        cur_sum-=arr[i][0];
    }
   return ans+cnt;
}
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      vector<vector<int>> arr;
      for(int i=0;i<A.size();i++){
          arr.push_back({A[i],i});
      }
      sort(arr.begin(),arr.end());
      unordered_map<int,int> new_ind;
      vector<long long> pre_sum(N);
      pre_sum[0] = arr[0][0];
      new_ind[arr[0][1]+1] = 1;
      for(int i=1;i<N;i++){
          pre_sum[i]=pre_sum[i-1]+arr[i][0];
         new_ind[arr[i][1]+1] = i+1;
      }
      vector<int> ans(Queries.size());
      for(int i=0;i<Queries.size();i++){
          int cnt = solve(Queries[i],pre_sum,arr,new_ind);
          ans[i] = cnt;
      }
      return ans;
    }
};