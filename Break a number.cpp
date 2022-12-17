/*
Link to the "Break a number" Problem ==>>  https://practice.geeksforgeeks.org/problems/break-a-number5913/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/7xVImZIe3Fg 

*/

class Solution{   
    public:
        int waysToBreakNumber(int N){
            long long int m = 1000000007; 
            return ((((N+1)%m)*((N+2)%m))/2)%m;
        }
};