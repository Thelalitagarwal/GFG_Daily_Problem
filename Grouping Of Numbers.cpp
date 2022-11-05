class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        int a[K]={0};
        for(int i=0; i<N; i++)
            a[arr[i]%K]++;
        int ans = 0;
        for(int i=1; i<=K/2; i++){
            if(i != K-i)
                ans += max(a[i], a[K-i]);
            else{
                if(a[i] != 0)
                    ans++;
            }
        }
        if(a[0] > 0)
            ans++;
        return ans;
    }
};