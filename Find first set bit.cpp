class Solution{
    public:
    unsigned int getFirstSetBit(int n){
        if(n==0) return 0;
        unsigned int c = 1;
        while(n){
            if(n&1)
                return c;
            n>>=1;
            c++;
        }
        return c;    
    }
};