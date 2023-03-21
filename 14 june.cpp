class Solution
{
  public:
         int findNum(int n)
      {    int low = 0, high =5*n, ans = 0;
           while(low<=high)
           {   int mid = (low+high)/2;
               int zeroes= find_no_of_Zeroes_factorial(mid);
               if(zeroes>=n)
               {   ans = mid;
                   high = mid-1; }
               else low = mid+1;
           }
           return ans;     }
        
        int find_no_of_Zeroes_factorial(int x)
        {   
             int denom = 5,  zeroes = 0;
             while(x>=denom)
             {  zeroes+=(x/denom);
                denom*=5; }
            return zeroes;
        }
};
