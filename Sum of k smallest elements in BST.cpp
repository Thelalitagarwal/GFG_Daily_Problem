void findSol(Node* root,int &k,int &sum){
    if(!root)
        return;
        
    findSol(root->left,k,sum);
    
    if(k<=0)
        return;
    k--;
    sum+=root->data;
    findSol(root->right,k,sum);
}

int sum(Node* root, int k) 
{ 
    int sum = 0;
    findSol(root,k,sum);
    return sum;
}