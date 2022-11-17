class Solution{
public:
	long long countSubarray(int arr[], int n, int k) {
	    long long ans = 0;
	    for (int i = 0 ; i < n ; i++){
	        for (int j = i ; j < n ; j++){
	            if (arr[j] > k) {
	                ans += (n - j);
	                break;
	            }
	        }
	    }
	    return ans;
	}
};