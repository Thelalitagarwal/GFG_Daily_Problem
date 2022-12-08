/* 

Link to the "Distance of nearest cell having 1" Problem ==>>  https://practice.geeksforgeeks.org/problems/3-divisors3942/1 
   
Link to the complete Explaination Video ==>> https://youtu.be/xcZLT7MIoag 
   
*/



class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<int>fin;
        vector<long long int>v;
        long long int p;
        long long int i,j;
        p=ceil(sqrt(*max_element(query.begin(), query.end())));
        long long int arr[p]={0};
        for(i=2;i<=sqrt(p);i++){
            
            for(j=i*i;j<=p;j+=i)
                arr[j]=1;
        }

        for(i=2;i<=p;i++){
            if(arr[i] == 0)
                v.push_back(i);
        }

        
        
        for(i=0;i<query.size();i++){
            
            long long int target=query[i],c=0,index;
            
            if(target == 2 || target == 1 || target==3)
                fin.push_back(0);
            else{
                
            long long int l=0,r=v.size()-1,m=(l+r)/2;
            
            while(l<=r){
                
                if(v[m]*v[m]<target){
                    c++;
                    index=m;
                    l=m+1;
                }
                else if (v[m]*v[m] ==  target){
                    c++;
                    index=m;
                    break;
                }
                else if (v[m]*v[m] > target){
                    r=m-1;
                }
                m=(l+r)/2;
            }
            if(c>0)
                fin.push_back(index+1); }
        }
        return fin;
    }
};
