#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        priority_queue<int,vector<int>,greater<int>> heap;
        for(int i=0;i<n;i++){
            heap.push(arr[i]);
        }
        int count=0;
        while(heap.size()>1 && k>heap.top()){
            int minimum=heap.top();
            heap.pop();
            int minimum_second=heap.top();
            heap.pop();
            heap.push(minimum+minimum_second);
            count++;
        }
        if(heap.top()>=k){
            return count;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends