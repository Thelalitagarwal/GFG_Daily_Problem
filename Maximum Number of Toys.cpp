const int N=1e6+5;
int fr[N];
class tree{
public:
  vector<long long> bit;
  tree(){
    bit=vector<long long>(N);
  }
  void add(int node,int v)
  {
     for(;node<N;node+=(node&(-node)))
      bit[node]+=v;
  }
  long long get(int node)
  {
    long long x=0;
    for(;node>0;node-=(node&(-node)))
      x+=bit[node];
    return x;
  }
};
tree obj1,obj2;


class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
    vector<int> res;

    for(auto i:A){
      fr[i]++;
    }

    for(int i=0;i<A.size();i++){
      obj1.add(A[i],A[i]);
      obj2.add(A[i],1);
    }
    for(auto i:Queries){
      long long C=i[0];
      for(int j=2;j<i.size();j++){
        obj1.add(A[i[j]-1],-A[i[j]-1]);
        obj2.add(A[i[j]-1],-1);
      }
      long long lw=1,hg=1e6;
      long long pos=1e6;
      while(lw<=hg){
        int mid=(lw+hg)/2;
        if(obj1.get(mid)>=C){
          pos=mid;
          hg=mid-1;
        }
        else{
          lw=mid+1;
        }
      }

      long long ans=obj2.get(pos-1);
      long long mx=min((C-obj1.get(pos-1))/pos,(long long)fr[pos]);
      ans+=mx;
      res.push_back(ans);
      for(int j=2;j<i.size();j++){
        obj1.add(A[i[j]-1],A[i[j]-1]);
        obj2.add(A[i[j]-1],1);
      }
    }
    for(int i=0;i<A.size();i++){
      obj1.add(A[i],-A[i]);
      obj2.add(A[i],-1);
      fr[A[i]]--;
    }
    return res;
  }
};
