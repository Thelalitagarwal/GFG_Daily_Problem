class Solution {	
public:
	int countTriplets(vector<int>nums){
	    int small = 0;
	    int large = 0;
	    int ans = 0;
	    for(int i = 1;i<nums.size()-1;i++){
	        small=0,large = 0;
	        for(int j = 0;j<i;++j){
	            if(nums[j]<nums[i]) small++;
	        }
	        for(int j = i+1;j<nums.size();++j){
	            if(nums[j]>nums[i]) large++;
	        }
	        ans+=(small*large);
	    }
	    return ans;
	}
};