class Solution {
  public:
    int isPossible(int N, int arr[]) {
        long s = 0;
        for(int i=0;i<N;i++)
            s = s+arr[i];
        return (s%3==0)?1:0;
    }
};