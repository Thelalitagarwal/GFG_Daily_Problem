/*
Link to the "Minimize the sum" Problem ==>> https://practice.geeksforgeeks.org/problems/86e609332c9ef4f6b8aa79db11a6c0808c4a1bca/1

Link to the complete Explaination Video ==>> https://youtu.be/Vnx0AKVGyLQ 

*/

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue< int, vector<int>, greater<int> > pq(arr.begin(), arr.end());
        int ans = 0;
        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            ans += x + y;
            pq.push({x+y});
        }
        
        return ans;
    }
};