class Solution{
public:
vector<int> generateNextPalindrome(int num[], int n) {
       vector<int>ans;
       bool t=true;
       for(int i=0;i<n;i++){
           if(num[i]!=9)t=false;
       }
       if(t){
           ans.push_back(1);
           for(int i=0;i<n-1;i++)ans.push_back(0);
           ans.push_back(1);
           return ans;
       }
       bool flag=false;
        for(int i=0;i<n/2;i++)
        {
            if(num[n-1-i]>num[i])
            flag=false;
            else if(num[n-1-i]<num[i])
            flag=true;
            num[n-1-i]=num[i];
        }
        if(flag){
            for(int i=0;i<n;i++)ans.push_back(num[i]);
            return ans;
        }
       if(n%2==0){
           for(int i=0;i<n/2;i++)ans.push_back(num[i]);
           int c=1;
           for(int i=(n/2) -1;i>=0;i--){
               ans[i]+=c;
               c=ans[i]/10;
               ans[i]%=10;
               ans.push_back(ans[i]);
           }
       }
       else{
           for(int i=0;i<(n+1)/2;i++)ans.push_back(num[i]);
           int c=1;
           for(int i=(n/2);i>=0;i--){
               ans[i]+=c;
               c=ans[i]/10;
               ans[i]%=10;
               if(i!=(n/2))
               ans.push_back(ans[i]);
           }
       }
       return ans;
    }
};