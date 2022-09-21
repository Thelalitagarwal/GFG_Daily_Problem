class Solution
{
   public:
    string ReFormatString(string s, int k){
        int num=0, a=0;;
        for(int i=0; i<s.length(); i++){
            if(s[i]!='-'){
                num++;
            }
        }
    	string ans="";
    	string s2=s;
    	reverse(s2.begin(), s2.end());
    	int count =0;
    	for(int i=0; i<s2.length(); i++){
    	    if(count<k){
    	        if(s2[i]!='-'){
    	             if (s2[i] >= 'a' && s2[i] <= 'z'){s2[i] = s2[i] - 32;}
    	            ans+=s2[i];
    	            count++;
    	        }
    	    }else if(num>ans.length()-a){
    	        
    	        ans+='-';
    	        count=0;
    	        i--;
    	        a++;
    	       
    	    }
    	}
    	
    	reverse(ans.begin(), ans.end());
    	return ans;
    	
    }
};