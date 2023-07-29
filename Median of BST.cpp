int countnode(Node* root){
    if(!root){
        return 0;
    }
    else{
        return 1 + countnode(root->left) + countnode(root->right);
    }
}
void findnode(Node* root, int &c, int &val){
    if(!root){
        return;
    }
    else{
        findnode(root->left, c, val);
        c--;
        if(c == 0){
            val = root->data;
        }
        findnode(root->right, c, val);
    }
}
float findMedian(struct Node *root)
{
      //Code here
      int N = countnode(root);
      if(N % 2){
          int val = -1, c = (N + 1) / 2;
          findnode(root, c, val);
          return (float)val;
      }
      else{
          int val = -1,val2 = -1,c = N / 2;
          findnode(root, c, val);
          c = N / 2 + 1;
          findnode(root, c, val2);
          float ans = (float)(val + val2) / (2.0);
          return ans;
      }
}