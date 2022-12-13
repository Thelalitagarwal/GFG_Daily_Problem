/*
Link to the "Distance of nearest cell having 1" Problem ==>>  https://practice.geeksforgeeks.org/problems/f04fd67b26b4828b6180715d8b1700426b637247/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/vEju9XDNSR0 

*/


class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        int max=INT_MIN,sum=0;
        for(int i=0;i<N;i++){
            if(arr[i]>max){
                max=arr[i];
            }
            sum+=arr[i];
        }
        int ans,l=max,h=sum,mid;
        while(l<=h){
            mid=(l+h)/2;
            int ctr=1,s=0;
            
            for(int i=0;i<N;i++){
                
                s+=arr[i];
                
                if(s>mid){
                    
                    ctr++;
                    
                    s=arr[i];
                    
                }
            }
            
            if(ctr>K){
                
                l=mid+1;
                
            }
            else{
                
                ans=mid;
                
                h=mid-1;
            }
        }
        return ans;
    }
};