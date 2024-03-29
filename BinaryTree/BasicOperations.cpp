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
void print2(node *root){
  //Iterative Pre-order Traversal
  if(root==NULL){
    return;
  }
  stack<node*> s;
  s.push(root);
  while(!s.empty()){
    node* n=s.top();
    s.pop();
    cout<<n->data<<" ";
    if(n->right){
      s.push(n->right);
    }
    if(n->left){
      s.push(n->left);
    }
  }
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
void printIn2(node *root){
  //Iterative In-order traversal
  if(root==NULL){
    return;
  }
  stack<node *> s;
  node *curr=root;
  while(1){
    if(curr){
      s.push(curr);
      curr=curr->left;
    }
    else{
      if(s.empty()){
        break;
      }
      curr=s.top();
      cout<<curr->data<<" ";
      s.pop();
      curr=curr->right;
    }
  }
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
void printPost2(node *root){
  //Iterative Post-order Traversal (Using 2 stacks)
  if(root==NULL){
    return;
  }
  stack<node*> s1;
  stack<node*> s2;
  s1.push(root);
  while(!s1.empty()){
    node *n=s1.top();
    s1.pop();
    s2.push(n);
    if(n->left){
      s1.push(n->left);
    }
    if(n->right){
      s1.push(n->right);
    }
  }
  while(!s2.empty()){
    cout<<s2.top()->data<<" ";
    s2.pop();
  }
}
void printPost3(node *root){
  //Iterative Post-order Traversal (Using 1 stack)
  if(root==NULL){
    return;
  }
  stack<node*> s;
  node* curr=root;
  while(curr || !s.empty()){
    if(curr){
      s.push(curr);
      s=s->left;
    }
    else{
      node *n=s.top()->right;
      s.pop();
      if(!n){
        n=s.top();
        s.pop();
        cout<<n->data<<" ";
        while(!s.empty() && n==s.top()->right){
          n=s.top();
          s.pop();
          cout<<n->data<<" ";
        }
      }
      else{
        curr=n;
      }
    }
  }
}

void printAll(node *root){
  //All traversals in one go
  vector<int> pre;
  vector<int> in;
  vector<int> post;
  
  
}

int size(node* root){
  //no. of edges
  if(root==NULL){
    return 0;
  }
  
}
int height(node* root){
  //no. of nodes
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

int diameter(node *root){
  //O(n^2) time
  if(root==NULL){
    return 0;
  }
  int h1=height(root->left);
  int h2=height(root->right);
  int op1=h1+h2;
  int op2=diameter(root->left);
  int op3=diameter(root->right);
  
  return max(op1,max(op2,op3));
}
pair<int,int> diameter(node *root){
  //O(n) time
  pair<int,int> p;
  //first->height & second->diameter
  if(root==NULL){
    p.first=p.second=0;
    return p;
  }
  pair<int,int> left=diameter(root->left);
  pair<int,int> right=diameter(root->right);
  
  p.first=max(left.first,right.first)+1;
  p.second=max(left.first+right.first,max(left.second,right.second));
  
  return p;
}
