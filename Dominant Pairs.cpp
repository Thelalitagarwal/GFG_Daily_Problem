class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        sort(arr.begin(),arr.begin()+(n/2));
        sort(arr.begin()+(n/2),arr.end());
        
        int count=0;
        int i=0,j=n/2;
        
        while(i<n/2 && j<n){
            if(arr[i]>=5*arr[j]){
                count+=n/2-i;
                j++;
            }
            else{
                i++;
            }
        }
        return count;
    }   
};