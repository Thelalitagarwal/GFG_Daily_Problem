/*
Link to the "Carpet into Box" Problem ==>> https://practice.geeksforgeeks.org/problems/230d87552a332a2970b2092451334a007f2b0eec/1

Link to the complete Explaination Video ==>> https://youtu.be/QDdZQz9KuA4 

*/
class Solution{
    public:
    int carpetBox(int A, int B, int C, int D) {

        if((A<=C&&B<=D) || (B<=C&&A<=D)){
            return 0;  
        } 
        if(A>C && A>D){
            return 1+carpetBox(A/2,B,C,D);  
        } 
        if(B>C && B>D){
            return 1+carpetBox(A,B/2,C,D);
        } 
        return min(1+carpetBox(A/2,B,C,D), 1+carpetBox(A,B/2,C,D));
    }
};