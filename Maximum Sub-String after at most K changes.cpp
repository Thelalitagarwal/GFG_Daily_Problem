class Solution {
	public:
		int characterReplacement(string s, int k){
		    int mx = 1;
		    for(char ch = 'A' ; ch<='Z' ; ch++){
		        int ct = 0;
		        int left = 0 , right = 0;
		        while(right < s.size()){
		            if(s[right] == ch){
		                mx = max(mx , right - left + 1);
		                right++;
		            }
		            else{
		                if(ct < k){
		                    ct++;
		                    mx = max(mx , right - left + 1);
		                    right++;
		                }
		                else{
		                    while(left < s.size() && s[left] == ch){
		                        left++;
		                    }
		                    left++;
		                    ct--;
		                }
		            }
		        }

		    }
		    return mx;
		}
};