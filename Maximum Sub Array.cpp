class Solution{
public:
	vector<int> findSubarray(int arr[], int n){
	    pair<int,int>p;
	    p.first=0;
	    p.second=-1;
	    int i=0;
	    int j=0;
	    int maxi=0;
	    int sum=0;
	    while(j<n){
	        if(arr[j]>=0){
	            sum+=arr[j++];
	        } 
	        else{
	            if(maxi<sum){
	                maxi=sum;
	                p.first=i;
	                p.second=j-1;
	            }
	            sum=0;
	            i=j+1;
	            j+=1;
	        }
	    }
	    if(maxi<sum){
            maxi=sum;
            p.first=i;
            p.second=j-1;
	    }
	    vector<int>ans;
	    for(int k=p.first;k<=p.second;k++){
	        ans.push_back(arr[k]);
	    }
	    if(ans.empty()){
	        ans.push_back(-1);
	    }
	    return ans;
	}
};