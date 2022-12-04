class Solution{
    void util(vector<int> &a,vector<int> &b, string &s){
        int p=0,q=0;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                while(a[p]==0)
                    p++;
                s[i]= p+'a';
                a[p]--;
            }
            else{
                while(b[q]==0)
                    q++;
                s[i] = q+'a';
                b[q]--;
            }
        }
    }
    public:
    string rearrange (string S, int N){
        vector<int> v(26,0) , c(26,0);
        int v_count=0;
        for(auto x:S){
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
                v_count++;
                v[x-'a']++;
            }
            else
                c[x-'a']++;
        }
        int c_count = N - v_count;
        
        if(abs(v_count - c_count)>1)
        return "-1";
    
        if(v_count > c_count)
            util(v , c , S);
        
        else if(v_count < c_count)
            util(c , v , S);
        
        else{
            for(int i=0;i<26;i++){
                if(c[i]>0){
                    util(c , v , S);
                    break;
                }
                if(v[i]>0){
                    util(v , c , S);
                    break;
                }
            }
        }
        return S;
    }
};