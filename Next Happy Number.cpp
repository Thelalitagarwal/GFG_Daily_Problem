class Solution{
public:
    int isHappy(int N){
        if (N == 1 || N == 7) 
            return 1; 
        int sum = N, x = N; 
        while(sum > 9) { 
            sum = 0; 
            while (x > 0) { 
                int d = x%10; 
                sum += d*d; 
                x/=10; 
            } 
            if (sum == 1) 
                return 1; 
            x = sum; 
        } 
        if(sum == 7) 
            return 1; 
        return 0;
    }
    int nextHappy(int N)
    {   
        int x=N+1;
        int res=x;
        while(1)
        {
            if(isHappy(x))
                return x;
            x++;
            res=x;
        }
    }
};