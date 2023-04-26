class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& arr){
        if(n>m){
            return false;
        }
        if(arr[0]==0 && arr[1]==0){
            arr[0]=1;;
            n--;
        }

        for(int i=1;i<m-1;i++){
            if(arr[i-1]==0 && arr[i]==0 && arr[i+1]==0){
                arr[i]=1;   
                n--;
            }else{
                continue;
            }
        }
        
        if(arr[m-1]==0 && arr[m-2]==0){
          n--;  
        } 

        if(n<=0){
            return true;    
        }
        return false;
    }
};