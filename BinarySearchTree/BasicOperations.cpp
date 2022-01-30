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

node* insert(node* root,int d){
  if(root==NULL){
    return new node(d);
  }
  if(d<=root.data){
    root->left=insert(root->left,d);
  }
  else{
    root->right=insert(root->right,d);
  }
  return root;
}

node* build(){
  int d;
  cin>>d;
  node* root
  while(d!=-1){
    root=insert(root,d);
    cin>>d;
  }
  return root;
}

//Code for all traversal methods remain the same
//Inorder Print of a BST is always sorted

bool search(node* root,int k){
  if(root==NULL){
    return false;
  }
  if(root->data==k){
    return true;
  }
  else if(k<root->data){
    return search(root->left,k);
  }
  else{
    return search(root->right,k);
  }
}

void deletion(node* root,node* k){
  if(root==NULL || k==NULL){
    return;
  }
  if(root->left && root->right){
  
  }
  else if(root->left || root->right){
  
  }
  else{
    
  }
}
