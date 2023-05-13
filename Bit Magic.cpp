class Solution {
  public:
    int bitMagic(int n, vector<int> arr) {
        int mismatch=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(arr[i]!=arr[j]){
                mismatch++;
            }
            i++;
            j--;
        }
        if(mismatch==0)
            return 0;
        else 
            return (mismatch%2==0) ? (mismatch/2) : ((mismatch/2)+1);
    }
};