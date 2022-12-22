class Solution{
public:

    long long int findSubarray(vector<long long int> &arr, int n ) {
        long long int count=0;
        unordered_map<long long int,int>mp;
        mp[0]=1;
        long long int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
            if(mp[sum])
            {
                count+=mp[sum];
            }
            mp[sum]++;
        }
        return count;
    }
};