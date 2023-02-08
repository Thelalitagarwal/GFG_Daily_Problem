class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long> ans;
        int rk = 0, ck = 0;
        long long temp = n*n;
        int row[100001] = {0};
        int col[100001] = {0};
        for(int i = 0;i<k;i++)
        {
            int r = arr[i][0], c = arr[i][1];
            if(row[r] == 1 && col[c] == 1)
            {
                ans.push_back(temp);
            }
            else if(row[r] == 1)
            {
                col[c] = 1;
                ck++;
                temp = temp - n + rk;
                ans.push_back(temp);
            }
            else if(col[c] == 1)
            {
                row[r] = 1;
                rk++;
                temp = temp - n + ck;
                ans.push_back(temp);
            }
            else
            {
                row[r] = 1;
                col[c] = 1;
                temp = temp - n + ck - n + rk + 1;
                ck++;
                rk++;
                ans.push_back(temp);
            }
        }
        return ans;
  }
};