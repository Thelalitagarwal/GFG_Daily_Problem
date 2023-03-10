class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n){
        long long maxi1=INT_MIN,maxi2=INT_MIN,maxi3=INT_MIN;
        long long mini1=INT_MAX,mini2=INT_MAX;
        for(int i=0;i<n;i++){
            if(maxi1<=arr[i]){
                maxi3=maxi2;
                maxi2=maxi1;
                maxi1=arr[i];
            }
            else if(maxi2<=arr[i]){
                maxi3=maxi2;
                maxi2=arr[i];
            }
            else if(maxi3<=arr[i]){
                maxi3=arr[i];
            }
            if(mini1>=arr[i]){
                mini2=mini1;
                mini1=arr[i];
            }
            else if(mini2>=arr[i]){
                mini2=arr[i];
            }
        }
        return max(maxi1*maxi2*maxi3,mini1*mini2*maxi1);
    }
};