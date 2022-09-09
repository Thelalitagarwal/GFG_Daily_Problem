class Solution{
	public:
	string digitsNum(int N)
    {
        int c=N;
        string s="";
        
        while(c>9){
            s+="9";
            c-=9;
        }
        
        string temp=to_string(c);
        
        s+=temp;
        
        reverse(s.begin(),s.end());
        
        for(int i=0;i<N;i++){
            s+="0";
        }
        return s;
    }
};
