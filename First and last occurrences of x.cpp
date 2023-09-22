class Solution{
    public:
    vector<int> find(int arr[], int n , int x ){
        int a =-1,b=-1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                a=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==x){
                b=i;
                break;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};