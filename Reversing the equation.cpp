Link to the problem: https://practice.geeksforgeeks.org/problems/reversing-the-equation2205/1

class Solution{
  public:
    string reverseEqn (string s){
        string res = ""; 
        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9')
                temp += s[i];
            else {
                res = s[i] + temp + res; 
                temp = "";
            }
        }
        if(temp != "") 
            res = temp + res;
        return res; 
    }
};
