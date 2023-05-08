class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            long long num = 0, a = 1;
            int n = s.length();
            
            for(int i = n-1; i >=0; i--){
                if(s[i] == '1'){
                    num = (num+a)%m;
                }
                a = (a*2)%m;
            }
            
            return num;
        }
};