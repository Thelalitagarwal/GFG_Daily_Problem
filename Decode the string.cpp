class Solution{
public:
    string decodedString(string s){
        stack<string>stkc;
        stkc.push("#");
        stack<int>stki;
        string ans = "";
        int cnt = 0;
        int cnt1=0;
        for(int i = 0 ; i < s.size() ;i++){
            if(s[i]-'0' >=0 && s[i]-'0' <=9){
                int n = 0;
                while(s[i]-'0' >=0 && s[i]-'0' <=9){
                    n = n*10 + s[i]-'0';
                    i++;
                }
                stki.push(n);
                i--;
            }
            else if(s[i]==']'){
                string temp="";
                while(!stkc.empty() && stkc.top()!="["){
                    temp = stkc.top() + temp;
                    stkc.pop();
                }
                stkc.pop();
                ans = temp;
                int n = stki.top();
                stki.pop();       
                for(int i = 0 ; i < n-1 ; i++){
                    ans = ans +  temp;
                }
                stkc.push(ans);
            }
            else{
                string temp = "";
                temp += s[i];
                stkc.push(temp);
            }
        }
        ans  ="";
        while(stkc.top()!="#"){
           ans = stkc.top() + ans;
           stkc.pop();
       }     
       return ans;
    }
};
