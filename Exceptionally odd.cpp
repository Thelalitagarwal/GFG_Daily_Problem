class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans^arr[i];
        }
        return ans;
    }
};