class Solution{
    public:
    int countSubstring(string S) {
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0;
        int sum = 0;
        for (char ch : S) {
            int val;
            if (isupper(ch)) {
                val = 1;
            }
            else {
                val = -1;
            }
            sum += val;
            if (map.find(sum) != map.end()) {
                ans += map[sum];
            }
            map[sum]++;
        }
        return ans;
    }
};