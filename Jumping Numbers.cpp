class Solution {
  public:
  
    void bfs(long long x, long long num, long long &ans){ 
        queue<long long> q; 
        q.push(num); 
        while (!q.empty()) { 
            num = q.front(); 
            q.pop(); 
            if (num <= x) {
                ans = max(ans, num);
                int last = num % 10; 
                if (last != 9) 
                    q.push((num * 10) + (last + 1)); 
      
                if (last != 0) 
                    q.push((num * 10) + (last - 1)); 
            } 
        } 
    } 

    long long jumpingNums(long long X) {
        long long ans=0;
        for (long long i = 1; i<=9 && i<=X; i++) 
            bfs(X, i, ans);
        
        return ans;
    }
};