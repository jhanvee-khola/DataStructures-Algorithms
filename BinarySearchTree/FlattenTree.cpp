class Tree{
  int data;
  node* left;
  node* right;
  
  node(int d){
    data=d;
    left=NULL;
    right=NULL;
  }
};

class node{
  //for linked-list
  public:
    Tree* head;
    Tree* tail;
};

node flattenTree(Tree* root){
  node l;
  if(root==NULL){
    l.head=l.tail=NULL;
    return l;
  }
  if(root->left==NULL && root->right==NULL){
    l.head=l.tail=root;
    return l;
  }
  else if(root->left!=NULL && root-right==NULL){
    node leftL=flattenTree(root->left);
    leftL.tail->right=root;
    l.head=leftL.head;
    l.tail=root;
    return l;
  }
  else if(root->left==NULL && root-right!=NULL){
    node rightL=flattenTree(root->right);
    root->right=rightL.head;
    l.tail=rightL.tail;
    l.head=root;
    return l;
  }
  //else case- both nodes present
  node leftL=flattenTree(root->left);
  node rightL=flattenTree(root->right);
  leftL.tail->right=root;
  root->right=rightL.head;
  l.head=leftL.head;
  l.tail=rightL.tail;
  return l;
}
