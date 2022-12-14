/*
Link to the "Complement" Problem ==>>  https://practice.geeksforgeeks.org/problems/complement3911/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/0gPixS7Fq8Q 

*/

class Solution{
public:
    vector<int> findRange(string str, int n) {
        int l = 0, local_max = 0, 
        global_max = 0, left = 0, right = -1;
        for(int i=0; i<n; i++){
            int num = str[i] == '0' ? 1 : -1;
            if(local_max < 0){
                if(num == 1){
                    l = i;
                    local_max = num;
                }
            }
            else{
                local_max+=num;
            }
            if(local_max > global_max){
                global_max = local_max;
                left  = l;
                right = i;
            }
        }
        if(right == -1)
            return {-1};
        return {left+1, right+1};
    }
};