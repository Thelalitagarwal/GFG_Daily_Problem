Link to the Problem: https://practice.geeksforgeeks.org/problems/find-kth-permutation-0932/1

class Solution{
public:
    string kthPermutation(int n, int k){
        string h="";
        int chk=1;
        for(int i=1;i<=n;i++){
            h+=to_string(i);
            chk*=i;
        }
        string ans="";
        int i=0,g=0,r=0;
        while(i<n){
           r=chk/(n-i),g=k/r;
           if(k%r==0) g--;
           ans+=h[g];
           h.erase(h.begin()+g);
           k=k-(r)*(g);
           i++;
           chk=r;
        }
        return ans;
    }
};
