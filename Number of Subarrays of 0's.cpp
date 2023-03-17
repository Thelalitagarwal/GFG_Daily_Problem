/*
Link to the " Number of Subarrays of 0's " Problem ==>>  https://practice.geeksforgeeks.org/problems/0960a833f70b09c59444ea487f99729929fc8910/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/_asnPb5AFtM

*/

long long int no_of_subarrays(int n, vector<int> &arr) {
    long ans = 0;
    long cnt = 0;
    
    for(int i = 0; i < n; i++){
        
        if(arr[i] == 0){
            cnt++;
        } 
        else{
            ans += ((long)(cnt*(cnt+1))/2);
            cnt = 0;
        }
    }
    if(cnt != 0){
        ans += ((long)(cnt*(cnt+1))/2);
    }
    return ans;
}