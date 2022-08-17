class Solution {
public:
	vector<vector<int>>m={ {2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
	
    bool isValid(int x, int y, int N)
    {
        if(x>0 && y>0 && x<=N && y<=N)
        return true;
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	  queue<vector<int>>q;
	  q.push({KnightPos[0], KnightPos[1]});
	  bool vis[N+1][N+1]={false};
	  vis[KnightPos[0]][KnightPos[1]]=true;
	  int ans=0;
	  while(!q.empty())
	  {
	     int len=q.size();
	     for(int i=0; i<len; i++)
	     {
	         vector<int>temp=q.front();
	         q.pop();
	         if(temp[0]==TargetPos[0] && temp[1]==TargetPos[1])
	            return ans;
	         for(int j=0; j<m.size(); j++)
	         {
	  if(isValid(temp[0]+m[j][0],temp[1]+m[j][1],N) && !vis[temp[0]+m[j][0]][temp[1]+m[j][1]])
	             {
	                 q.push({temp[0]+m[j][0],temp[1]+m[j][1]});
	                 vis[temp[0]+m[j][0]][ temp[1]+m[j][1]]=1;
	             }
	         }
	     }
	     ans++;
	  }
	  return -1;
	}
};