class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int ans=0,mx=0;
        for(int i=0;i<n;i++) {
            int val = arr[i]+mx;
            mx = max(mx, ans);
            ans = max(ans,val);
        }
        return ans;
	}
};