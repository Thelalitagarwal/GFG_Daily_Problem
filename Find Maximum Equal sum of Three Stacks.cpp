class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0,sum2=0,sum3=0;
        for(auto x:S1)sum1+=x;
        for(auto x:S2)sum2+=x;
        for(auto x:S3)sum3+=x;
        int i=0,j=0,k=0;
        while(i<N1 and j<N2 and k<N3){
            if(sum1==sum2 and sum1==sum3)return sum1;
            if(sum1>sum3 or sum1>sum2)sum1-=S1[i],i++;
            if(sum2>sum3 or sum2>sum1)sum2-=S2[j],j++;
            if(sum3>sum1 or sum3>sum2)sum3-=S3[k],k++;
        }
        return 0;
    }
};