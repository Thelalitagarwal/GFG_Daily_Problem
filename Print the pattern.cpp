class Solution{
public:
   vector<string> pattern(int n){
       vector<string> ans;
       int x = 1;
       int y = n * (n + 1);
       
       for(int i=0;i<n;i++){
           string st = "";
           for(int j=0;j<2*i;j++){
               st += '-';
           }
           int k = n - i;
           while(k){
               st += to_string(x);
               st += '*';
               k--;
               x++;
           }
           k = n - i;
           int num = y - n + 1;
           while(k){
               if(k == 1){
                   st += to_string(num);
                   num++;
                   k--;
               }
               else{
                   st += to_string(num);
                   st += '*';
                   num++;
                   k--;
               }
               y--;
           }
           
           y++;
           ans.push_back(st);
       }
       
       return ans;
   }
};
