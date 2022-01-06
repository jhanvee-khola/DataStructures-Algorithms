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

node* buildTree(){
  int d;
  cin>>d;
  
  if(d==-1){
    return NULL;
  }
  node* root=new node(d);
  root->left=buildTree();
  rooot->right=buildTree();
  return root;
}

void print(node* root){
  //Pre-Order Traversal
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
}

void printIn(node *root){
  //In-Order Traversal
  if(root==NULL){
    return;
  }
  printIn(root->left);
  cout<<root->data<<" ";
  printIn(root->right);
}

void printPost(node *root){
  //Post-Order Traversal
  if(root==NULL){
    return;
  }
  printPost(root->left);
  printPost(root->right);
  cout<<root->data<<" ";
}

int height(node* root){
  
}
void printLevel(node *root){
  //Level-Order Traversal
  
}
