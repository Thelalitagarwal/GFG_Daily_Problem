/*
Link to the "Distance of nearest cell having 1" Problem ==>>  https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/v855PUHgLLM 

*/


class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int arr[k] = {0};
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]%k]++;
        }
        if(arr[0]%2 || arr[k/2]%2){
            return false;
        }
        for(int i = 1; i < k/2; i++){
            if((arr[i] != arr[k-i])){
                return false;
            }
        }
        return true;
    }
};