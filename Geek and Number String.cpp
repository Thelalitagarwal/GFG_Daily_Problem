class Solution{
public:
    bool ischeck(string s){
        return (s=="12" || s=="21" ||s=="34" ||s=="43" ||s=="56" ||s=="65" ||s=="78" ||s=="87" ||s=="09" ||s=="90");
    }
    int minLength(string s, int n) {
        stack<char>stk;
        for(int i=0;i<n;i++){
            stk.push(s[i]);
        }
        stack<char>help;
        while(!stk.empty()){
            if(!help.empty()){
                string x={stk.top()};
                string y={help.top()};
                string z=x+y;
                if(ischeck(z)){
                    help.pop();
                }
                else{
                    help.push(stk.top());
                }
                stk.pop();
            }
            else{
                help.push(stk.top());
                stk.pop();
            }
        }
        return help.size();
    }
};