class Solution {
    public:
        bool isCheck(vector<int> &arr, int days, int cs, long long int h){
            
            int n=arr.size();
            vector<long long> waterSupply(n,0);
            if(arr[0]<h){
                waterSupply[0]=h-arr[0];
                days-=(h-arr[0]);
            }
            if(days<0){
                return false;
            }
            for(int i=1;i<n;i++){
                waterSupply[i]=waterSupply[i-1];
                int actualHeight=arr[i];
                if(i>=cs){
                    actualHeight+=(waterSupply[i]-waterSupply[i-cs]);
                }
                else{
                    actualHeight+=waterSupply[i];
                }
                if(actualHeight<h){
                    waterSupply[i]+=(h-actualHeight);
                    days-=(h-actualHeight);
                }
                if(days<0){
                    return false;
                }
            }
            return true;
        }

        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a){
            long long int ans=-1;
            long long int mini=*min_element(a.begin(),a.end());
            long long int maxi=INT_MAX/2;
            while(mini<=maxi){
                int guessHeight=(maxi+mini)/2;
                if(isCheck(a,k,w,guessHeight)==true){
                    ans=guessHeight;
                    mini=guessHeight+1;
                }
                else{
                    maxi=guessHeight-1;
                }
            }
            return ans;  
        }
};