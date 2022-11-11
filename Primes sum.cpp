class Solution {
public:
    bool isprime(int n)
    {
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }

    string isSumOfTwo(int n){
        for(int i=2;i<n-1;i++)
        {
            if(isprime(i) && isprime(n-i))
                return "Yes";
        }
        return "No";
    }
};
