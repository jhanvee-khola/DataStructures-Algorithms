class node{
  int data;
  node* left;
  node* right;
  
  node(int d){
    data=d;
    left=NULL;
    right=NULL;
  }
};

int sumReplacement(node* root){
  if(root==NULL){
    return 0;
  }
  if(root->left==NULL && root->right==NULL){
    return root->data;
  }
  int temp=root->data;
  int l=sumReplacement(root->left),r=sumReplacement(root->right);
  root->data=l+r;
  return temp+root->data;
}
