class Solution{
    public:
    int findK(int a[MAX][MAX],int n,int m,int k){
        int left=0,top=0;
        int bot=n-1,right=m-1;
        k--;//k value will be changed ,k is a copy of originl value so in main func. k will have same value
        while(left<=right && top<=bot){
            for(int i=left;i<=right;i++){
            if(k==0){
               return a[top][i];
            }
            k--;
        }
        top++;
        for(int i=top;i<=bot;i++){
            if(k==0){
               return a[i][right];
            }
            k--;
        }
        right--;
        for(int i=right;i>=left;i--){
            if(k==0){
               return a[bot][i];
            }
            k--;
        }
        bot--;
        for(int i=bot;i>=top;i--){
            if(k==0){
                return a[i][left];
            }
            k--;
        }
        left++;
    }
    return -1;
    }
};