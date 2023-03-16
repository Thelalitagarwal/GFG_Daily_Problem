class Solution{   
  public:
    string secondSmallest(int S, int D){
         if(S==1 || D==1) return "-1";
         if(S>=9*D) return "-1";
         string ans(D,'0');
         int sum=S;
         int last=-1;
         for(int i=D-1;i>=0;i--){
             if(sum>9){
                 ans[i]='9';
                 sum-=9;
             }
             else if(sum>0){
                 ans[i]='0'+sum;
                 last=i;
                 sum=0;
             }
             else{
                 ans[i]='0';
             }
         }
         if(ans[0]=='0'){
             ans[0]='1';
             ans[last]-=1;
         }
         int l=D-2;
         while(ans[l]=='9') l--;
         ans[l]+=1;
         ans[l+1]-=1;
         return ans;
    }
};