class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
     for(int i=0;i<n;++i) 
       if(arr[i] % 2 != 0)   return 1;
     return 2;
    }
};