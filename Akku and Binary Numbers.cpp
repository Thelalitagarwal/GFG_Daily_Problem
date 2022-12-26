#define ll long long int 

class Solution{
    vector<ll> nums;
public:
    void precompute(){
        for(int i=0;i<63;i++){
            for(int j=i+1;j<63;j++)
            {
                for(int k=j+1;k<63;k++)
                {
                    ll temp = pow(2,i) + pow(2,j) + pow(2,k);
                    nums.push_back(temp);
                }
            }
        }
        sort(nums.begin(),nums.end());
    }
    
    long long solve(long long l, long long r){
        return (upper_bound(nums.begin(),nums.end(),r) -nums.begin()) - 
        (lower_bound(nums.begin(),nums.end(),l) - nums.begin());
    }
    
};