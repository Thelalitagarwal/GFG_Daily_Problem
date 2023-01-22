/*
Link to the "GCD Array" Problem ==>> https://practice.geeksforgeeks.org/problems/2b70d42632a4e207569c6d2d777383e4603d6fe1/1

Link to the complete Explaination Video ==>> https://youtu.be/3LhOG0GP6TA 

*/

class Solution {
  public:
  
    int solve(int N, int K, vector<int> &arr) {
        
        int sum=0;
        vector<int>pre(N,0);
        for(int i=0;i<N;i++){
            sum+=arr[i];   
            pre[i]=sum;
        }
        vector<int>divisors;
        for(int i=1;i*i<=sum;i++){
            if(sum%i==0){       
                divisors.push_back(i);
                if(i!=sum/i){
                    divisors.push_back(sum/i);
                }
           }
        }
        int ans=1;
        for(auto d:divisors){
            int partions=0;
            for(int i=0;i<N;i++){
                if(pre[i]%d==0){
                    partions++;
                }              
                if(partions>=K){
                    ans=max(ans,d);
                }
            }
        }
        return ans;
    }
};