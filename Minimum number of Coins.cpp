class Solution{
public:
    vector<int> minPartition(int n)
{
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int p = 9;
    vector<int> res;
    for(int i=p; i>=0; i--){
        if(a[i]<=n){
            int x = n/a[i];
            for(int j=0; j<x; j++) res.push_back(a[i]);
            n = n%a[i];
        }
    }
    return res;
}
};