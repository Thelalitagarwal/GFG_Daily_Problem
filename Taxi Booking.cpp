class Solution{
public:
    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        int ans = INT_MAX;
        for(int i=0;i<N;i++){
            int num = abs(pos[i]-cur)*time[i];
            ans = min(ans,num);
        }
        return ans;
    }
};