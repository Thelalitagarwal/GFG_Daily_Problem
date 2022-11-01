class Solution{   
public:
    int countno(vector<vector<int>> &arr, int mid, int i, int c)
    {
        int low = 0, high = c - 1;
        while(low <= high)
        {
            int m = low + (high - low) / 2;
            if(arr[i][m] <= mid)
            {
                low = m + 1;
            }
            else
            high = m - 1;
        }
        return low;
    }
    int median(vector<vector<int>> &arr, int r, int c){
        // code here   
        int low = 1;
        int high = 2001;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int count = 0; // <= mid
            
            for(int i = 0; i < r; i++)
            count += countno(arr, mid, i, c);
            
            if(count <= (r * c) / 2)
            low = mid + 1;
            else
            high = mid - 1;
            
        }
        return low;
    }
};