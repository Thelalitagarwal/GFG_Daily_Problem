class Solution {
  public:
    string fn(Node* root, unordered_map<string,int>&m){
        if(root==NULL) return "";
        string s = fn(root->left,m) + to_string(root->data) + fn(root->right,m);
        m[s]++;
        return s;
    }
    int dupSub(Node *root){
        unordered_map<string,int> m;
        fn(root,m);
        for(auto p : m) if(p.first.length()>2 and p.second>1) return 1;
        return 0;
    }
};