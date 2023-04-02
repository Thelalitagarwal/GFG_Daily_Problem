//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        int m = arr.size();
        int n = arr[0].size();
        
        queue<pair<int, int>> q;
        q.push({start_x, start_y});
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[start_x][start_y] = true;
        
        vector<int> coins;
        
        int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[8] = {-1, 1, -2, 2, 2, -2, 1, -1};
        
        while(!q.empty()){
            int size = q.size();
            int coinsInThisStep = 0;
            while(size--)
            {
                auto node = q.front();
                q.pop();
                
                int currX = node.first;
                int currY = node.second;
                
                coinsInThisStep += arr[currX][currY];
                
                for(int dir=0; dir<8; dir++)
                {
                    int newX = currX + dx[dir];
                    int newY = currY + dy[dir];

                    if(newX >= 0 and newY >= 0 and newX < m and newY < n and !vis[newX][newY])
                    {
                        
                        vis[newX][newY] = true;
                        q.push({newX, newY});
                    }
                    
                }
                
            }
            coins.push_back(coinsInThisStep);
        }
        int size = coins.size();
        int maxi=INT_MIN;
        int ans;
        for(int i=size-1; i>=0; i--){
            if(coins[i] + i < size){
                coins[i] += coins[coins[i] + i];
            }
            if(coins[i] >= maxi){
                maxi = coins[i];
                ans = i;
            }
        }
        return ans;
    }
};