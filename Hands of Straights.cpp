class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        if(N%groupSize != 0) return false; 
        if(N == 1 || groupSize == 1) return true;
        map<int,int> f;
        for(int i: hand)  f[i]++;
        for(auto i: f){
            int v=i.first;
            int c=i.second;
            if(c==0)    continue;
            for(int j=v;j<v+groupSize;j++){
                if(f[j]==0 or f[j]<c)  return false;
                f[j]-=c;
            }
        }
        return true;
    }
};