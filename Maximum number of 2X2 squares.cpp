class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
       base=base/2 -1;
       return (base*(base+1)) /2;
    }
};