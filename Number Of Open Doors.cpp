class Solution {
  public:
    int noOfOpenDoors(long long n) {
        return floor(sqrt(n));
    }
};


// Solve the TLE in below code
class Solution {
  public:
    int noOfOpenDoors(long long n) {
        
        int ans=0;
        
        vector<int> a(n+1,1);
        
        for(long long i=2;i<n+1;i++){
            
            long long s=1;
            
            while((i*s)<n+1){
                if(a[i*s]){
                    a[i*s]=0;
                }
                else{
                    a[i*s]=1;
                }
                s++;
            }
        }
        
        for(long long i=1;i<n+1;i++){
            if(a[i]){
                ans++;
            }
        }
        
        return ans;
    }
};