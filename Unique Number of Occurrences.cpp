class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        set<int>s2;
        for(auto x: mp){
            s2.insert(x.second);
        }
        return mp.size()==s2.size();
        
    }
};