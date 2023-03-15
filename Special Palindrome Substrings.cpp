class Solution{
    //Complete the function and return minimum number of operations
    public:
    int findopern(string& temp,int num1,int m)
    {
        int start=0,end=temp.length()-1;
        int opern=0;
        while(start<=end)
        {
            if(temp[start]!=temp[end])
            {
                if(start>=num1 && end<=(num1+m-1)) return 1e9;
                opern++;
            }
            start++;
            end--;
        }
        return opern;
    }
    int specialPalindrome(string s1, string s2){
        int n=s1.length(),m=s2.length();
        string temp=s1;
        int mini=1e9;
        for(int i=0;i<=n-m;i++)
        {
            int op=0;
            // put s2 in s1 
            for(int j=0;j<m;j++)
            {
                if(temp[i+j]!=s2[j]) op++;
                
                temp[i+j]=s2[j];
            }
            // we have to find number of opern for palindrome
            mini=min(mini,op+findopern(temp,i,m));
            temp=s1;
        }
        if(mini==1e9) return -1;
        return mini;
    }
};