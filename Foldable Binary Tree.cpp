bool fold(Node* root1, Node* root2){
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 && root2)
        return fold(root1->left, root2->right)
               && fold(root1->right, root2->left);
    return false;
}
bool IsFoldable(Node* root)
{
    return fold(root,root);
}