class Solution{
public:
    Node* LCA(Node *root, int n1, int n2) {
        if (root == nullptr)
            return nullptr;

        if (root->data > n1 && root->data > n2)
            return LCA(root->left, n1, n2);

        if (root->data < n1 && root->data < n2)
            return LCA(root->right, n1, n2);

        return root;
    }
};