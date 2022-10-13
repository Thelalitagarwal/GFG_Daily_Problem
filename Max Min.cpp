class Solution{
    public:
    int findSum(int a[], int n){
	    int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n;i++){
    	    maxi=max(maxi,a[i]);
    	    mini=min(mini,a[i]);
    	}
    	return maxi+mini;
    }
};