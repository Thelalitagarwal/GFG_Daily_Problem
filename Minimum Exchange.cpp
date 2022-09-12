class Solution {
public:
int MinimumExchange(vector<vector<char>>matrix){
    int ans=0;
    
    for(int i=0;i<matrix.size();i++){ 
        
        char c='A';
        
        if(i%2==1){
            c='B';
        }
        
        for(int j=0;j<matrix[0].size();j++){
            
            if(matrix[i][j]!=c){
                ans++;
            }
            
            if(c=='A'){
                c='B';
            }
            else{
                c='A';
            }
        }
    }
    
    int a=matrix.size()*matrix[0].size();
    return min(ans,abs(a-ans));
}

};
