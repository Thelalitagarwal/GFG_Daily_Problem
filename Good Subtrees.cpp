class Solution{
    unordered_set<int> st;
    int res = 0;
    unordered_set<int> find_good_subtrees(Node *root, int k){
        if(!root) return st;
        unordered_set<int> l = find_good_subtrees(root -> left, k);
        unordered_set<int> r = find_good_subtrees(root -> right, k);
        for(auto &i: r){
            l.insert(i);
        }
        l.insert(root -> data);
        if(l.size() <= k) res++;
        return l;
    }
    
public:
    int goodSubtrees(Node *root,int k) {
        res = 0;
        find_good_subtrees(root, k);
        return res;
    }
};