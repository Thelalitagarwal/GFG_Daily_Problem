class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int mx=0,mn=1e9;
        for(auto it:mpp){
            if(it.second<mn){
                mn=it.second;
                mx=it.first;
            }
            else if(it.second==mn){
                mx=max(mx,it.first);
            }
        }
        return mx;
    }
};