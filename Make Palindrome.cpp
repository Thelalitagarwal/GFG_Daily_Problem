class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){                          
        priority_queue<string>q1;
        priority_queue<string>q2;
        for(int i=0;i<n;i++){
            q1.push(arr[i]);
            reverse(arr[i].begin(),arr[i].end());
            q2.push(arr[i]);
        }
        int chiggy=0;
        for(int i=0;i<n;i++){
            if(q1.top()!=q2.top()){
                chiggy=1;
                break;
            }
            else{
             q1.pop();
             q2.pop();
            }
        }
        if(chiggy==1){
           return 0;
            
        }
        else{
            return 1;
          
        }
    }
};