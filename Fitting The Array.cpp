class Solution{
public:
    
    bool isFit(int arr[], int brr[], int n){
        sort(arr,arr+n);
        sort(brr,brr+n);
        
        for(int i=0;i<n;i++){
            
            if(brr[i]<arr[i]){
                
                return false;
                
            }
        }
        return true;
    }
};