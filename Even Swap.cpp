class Solution{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n){
            int i=0;
            while(i<n){
                int j=i+1;
                while(j<n && ((a[j]+a[j-1])%2)==0){
                    j++;
                }
                sort(a.begin()+i,a.begin()+j,greater<int>());
                i=j;
            }
            return a;
        }
};