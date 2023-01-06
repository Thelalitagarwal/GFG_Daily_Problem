class Solution{   
  public:
    int shortestPath(int num1,int num2){

        bool prime[10000];
        memset(prime,1,sizeof(prime));
        for (int p = 2; p * p <= 9999; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= 9999; i += p)
                    prime[i] = false;
            }
        }

        queue<pair<int,int>> q;
        q.push({num1,0});
        unordered_set<int> st;
        st.insert(num1);
        while(q.empty()==false){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==num2){
                return y;
            }
            for(int k=1;k<=4;k++){
                for(int a=0;a<=9;a++){
                    int j = pow(10,4-k);
                    int l = (x/j)%10;
                    if(l!=a){
                        int newl = (x+(a-l)*j);
                        if(st.find(newl)==st.end() && prime[newl]==true && newl>999 && newl<10000){
                            q.push({newl,y+1});
                            st.insert(newl);
                        }
                    }
                }
            }
        }
        return -1;
    }
};