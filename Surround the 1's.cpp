class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int m=matrix.size(); 
        int n=matrix[0].size(); 
        int ans =0; 
        int count=0; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    count =0; 
                    for (int p = i - 1; p < i + 2; p++) {
                for (int q = j - 1; q < j + 2; q++) {
                    // Check if p and q are within valid boundaries
                    if (p >= 0 && p < m && q >= 0 && q < n && matrix[p][q] == 0) {
                        count++;
                    }
                }
            }
                    if(count>0 && count%2==0){ans++;}
                }
            }
        }
        return ans; 
    }
};