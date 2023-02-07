class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
           int length = 0;
           int temp = 0;
           int prod = 1;
           for(int i=0;i<n;i++){
               if(arr[i]==0){
                    temp=0;     prod=1;     continue;
               }
               if(arr[i]>0) prod*=1;
               else prod*=-1;
               temp++;
               if(prod>0)   length = max(length,temp);
           }
           temp=0;
           prod=1;
           for(int i=n-1;i>=0;i--){
               if(arr[i]==0){       
                    temp=0; prod=1; continue;
               }
               if(arr[i]>0) prod*=1;
               else prod*=-1;
               temp++;
               if(prod>0)   length = max(length,temp);
           }
           return length;
        }
};