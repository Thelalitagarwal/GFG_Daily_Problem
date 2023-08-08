class Solution{
    public:
    int countFractions(int n, int numerator[], int denominator[]){
        map<pair<int ,int>, int > m;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            int gcd = __gcd(numerator[i], denominator[i]);
            numerator[i] /= gcd;
            denominator[i] /=gcd;
            
            int x, y;
            x = numerator[i];
            y = denominator[i];
            
            int z = y - x;
            
            if(m.count({z, y}))
                ans += m[{z, y}];
                
            ++m[{numerator[i], denominator[i]}];
        }
        
        return ans;
    }
};