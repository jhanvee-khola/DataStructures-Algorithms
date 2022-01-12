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
  if(root==NULL){
    return 0;
  }
  return max(height(root->left),height(root->right))+1;
}
void printKthLevel(node *root,int k){
  if(root==NULL){
    return;
  }
  if(k==1){
    cout<<root->data<<" ";
  }
  printKthLevel(root->left,k-1);
  printKthLevel(root->right,k-1);
}
void printLevel(node *root){
  //Level-Order Traversal
  int h=height(root);
  for(int i=1;i<=h;i++){
    printKthLevel(root,i);
    cout<<endl;
  }
}

void bfs(node *root){
  //Breadth-First Traversal
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node *f=q.front();
    cout<<f.data<<" ";
    q.pop();
    if(f->left){
      q.push(f->left);
    }
    if(f->right){
      q.push(f->right);
    }
  }
  return;
}

void bfs(node *root){
  //Breadth-First Traversal (One Level in One Line)
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    node *f=q.front();
    if(f==NULL){
      cout<<endl;
      q.pop();
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout<<f.data<<" ";
      q.pop();
      if(f->left){
        q.push(f->left);
      }
      if(f->right){
        q.push(f->right);
      }
    }
  }
  return;
}
