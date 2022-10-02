class Solution {
    public:
         int minChar(string str){
            int l = str.length();
            int i;
            int j = l-1;
            int j_temp = j;
            i = 0;
            int count = 0;
            while (i<j)
            {
                if (str[i] == str[j])
                {
                    i++;
                    j--;
                }
                else{
                    count++;
                    i = 0;
                    j_temp--;
                    j = j_temp;   
                }
            }
            return count;
         }
};