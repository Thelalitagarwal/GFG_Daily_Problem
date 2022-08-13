class Solution{
public:
    static bool Compare(struct val p1, struct val p2){
        if(p1.second < p2.second)
        return true;
        else
        return false;
    }
    
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
     
        sort(p,p+n,Compare);
        int count = 1;
        int j = 1;
        int d = p[0].second;
        while(j<n){
            if(p[j].first > d){
                count++;
                d = p[j].second;
            }
            j++;
        }
        return count;
    }
};