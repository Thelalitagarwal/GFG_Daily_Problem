// Made By rayarka26
class Solution{   
public:
    bool isPalin(string s){
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i]!= s[j]) return false;
            else{
                i++; j--;
            }
        }
        return true;
    }
    int addMinChar(string str){    
        //code here
        if(isPalin(str)) return 0;
        for(int i = str.length()-1;i>=0;i--)
        {
            if(isPalin(str.substr(0,i))) return str.length()- i;
            
        }
        return str.length();
    }
};
