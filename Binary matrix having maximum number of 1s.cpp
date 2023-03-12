class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
         int mxcount = 0;
        int row_num = 0;
        for(int i = 0; i<N; i++){
             auto upper = upper_bound(mat[i].begin(), mat[i].end(), 0) ;
             int temp =  N - (upper - mat[i].begin());
             if(temp > mxcount){
                 mxcount = temp;
                 row_num = i;
             }
        }
       return {row_num , mxcount};
    }
};
