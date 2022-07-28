#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    long long int t[1001][1001];

    long long func(int n,int k){
        if(k>n){
            return 0;
        }
        else if(k==0 || k==n){
            return 1;
        }
        else if(t[n][k]){
            return t[n][k];
        }
        else{
            return t[n][k]=(func(n-1,k)%1000000007+func(n-1,k-1)%1000000007)%1000000007;
        }
    }

    int knots(int m, int n, int k){
        memset(t,0,sizeof(t));
        long long int a=func(m,k);
        long long int b=func(n,k);
        int ans=((a%1000000007)*(b%1000000007))%1000000007;
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int M, N, K;
        cin>>M>>N>>K;
        
        Solution ob;
        cout<<ob.knots(M, N, K)<<"\n";
    }
    return 0;
}
