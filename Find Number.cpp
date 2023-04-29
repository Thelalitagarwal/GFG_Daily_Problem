class Solution{
public:
    long long findNumber(long long N){
        // Code here
        int n=(log2(N)/log2(5));
        
        vector<long long>v;
        v.push_back(1);
        int i;
        for(i=1;i<=n;i++)
        {
             v.push_back(v[i-1]*5);
             if(N<=v[v.size()-1])
             break;
             N-=v[v.size()-1];
             
        }
        v.erase(v.begin()+v.size()-1);
        
        long long res=0;
        n=i;
        vector<int> avail(6,0);
        avail[1]=1,avail[2]=3,avail[3]=5,avail[4]=7,avail[5]=9;
        bool flag=0;
        for(i=1;i<n;i++)
        {
            flag=0;
            if(N%v[n-i]==0)
            flag=1;
            int temp=(N/v[n-i]);
            N-=1LL*(temp*v[n-i]);
            if(!flag)
            res=res*10+(avail[temp+1]);
            else
            {
            res=res*10+(avail[temp]);
            break;
            } 
            
        }
        while(flag && i<n)
        {
            res=res*10+9;
            i++;
        }
        if(!flag)
        res=res*10+(avail[N]);
        return res;
        
    }
};