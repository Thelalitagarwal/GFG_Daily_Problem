class Solution{
	public:
	 void shuffleArray(int arr[],int n)
    {
        int len = n/2;
        for(int i=1; i<n-1; i++){
            int currNum = arr[i] ,currPos = i;
            while(currNum > 0){
                int newPos = currPos < len ? 2*currPos : 2*(currPos-len)+1;
                int newNum = arr[newPos];
                arr[newPos] = -currNum;
                currNum = newNum;
                currPos = newPos;
            }
        }
        for(int i=0; i<n; i++) if(arr[i] < 0) arr[i] = -arr[i];
    }
};