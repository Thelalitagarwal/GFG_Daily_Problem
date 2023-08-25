class Solution{
public:	
	int isPalindrome(string S){
	    string RS=S;
	    reverse(RS.begin(), RS.end());
	    return (RS==S);
	}
};