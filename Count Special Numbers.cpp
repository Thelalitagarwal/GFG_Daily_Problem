class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        unordered_map<int, int> frequency;
        unordered_set<int> distinctElements;
        int maxVal = 0;
        for (int i : arr) {
            distinctElements.insert(i);
            maxVal = max(i, maxVal);
            frequency[i]++;
        }
        unordered_set<int> specialNumbers;
        for (auto i : distinctElements) {
            for (int j = 2 * i; j <= maxVal; j += i) {
                if (distinctElements.find(j) != distinctElements.end()) {
                    specialNumbers.insert(j);
                }
            }
        }
        int ans = 0;

        for (auto ele : frequency) {
            if (ele.second > 1) {
                ans += ele.second;
            } else if (specialNumbers.find(ele.first) != specialNumbers.end()) {
                ans++;
            }
        }
        return ans;
    }
};