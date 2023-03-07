class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
        int ans=INT_MIN;
        int sum=0;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int level=0;
        while(!q.empty()){
            Node* node=q.front().first;
            int curr=q.front().second;
            q.pop();
            if(level==curr) {
                sum+=node->data;
            }else{
                ans=max(ans,sum);
                sum=node->data;
                level=curr;
            }
            if(node->left) q.push({node->left,curr+1});
            if(node->right) q.push({node->right,curr+1});
        }
        ans=max(ans,sum);
        return ans;
    }
};