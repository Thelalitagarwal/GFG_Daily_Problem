class Solution{   
public:
    int appleSequences(int n, int m, string &s){
        // code here 
        int maxi=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i]=='O')
            v.push_back(i);
        }
        for(int i=0;i<n;i++){
            auto it1=lower_bound(v.begin(),v.end(),i);
            int firstOrangeIndex=it1-v.begin();
            int lastOrangeIndex=firstOrangeIndex+m;
            if(it1==v.end() or lastOrangeIndex>v.size()-1){
                maxi=max(maxi,n-i);
                break;
            }
            maxi=max(maxi,v[lastOrangeIndex]-i);
        }
        return maxi;
    }
};