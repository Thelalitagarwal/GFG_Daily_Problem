class Solution{
public:
    int inSequence(int A, int B, int C){
        if(A==B) return 1;
        if( C>0 && (B-A)>0 && ((B-A)% C)==0) return 1;
        if( C<0 && (B-A)<0 && ((B-A)% C)==0) return 1;
        return 0;
    }
};