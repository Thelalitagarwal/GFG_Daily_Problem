class Solution {
  public:
    vector<int> maximumValue(Node* node) {
        //code here
        queue<Node*> que;
        vector<int> ans;
        que.push(node);
        while(que.size()>0) {
            int s = que.size();
            int m=0;
            while(s--) {
                Node* p = que.front();
                m = max(m,p->data);
                que.pop();
                if(p->left!=NULL) que.push(p->left);
                if(p->right!=NULL) que.push(p->right);
            }
            ans.push_back(m);
        }
        return ans;
    }
};
