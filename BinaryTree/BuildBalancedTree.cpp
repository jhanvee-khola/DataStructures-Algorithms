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

node* buildBalanced(int a[],int s,int e){
  if(s>e){
    return NULL;
  }
  int mid=(s+e)/2;
  node* root=new node(a[mid]);
  root->left=buildBalanced(a,s,mid-1);
  root->right=buildBalanced(a,mid+1,e);
  return root;
}
