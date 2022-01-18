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

pair<int,bool> heightBalanced(node *root){
  pair<int,bool> p;
  //first=>height & second=>isBalanced
  if(root==NULL){
    p.first=0;
    p.second=true;
    return p;
  }
  pair<int,bool> left=heightBalanced(root->left);
  pair<int,bool> right=heightBalanced(root->right);
  p.first=max(left.height,right.height)+1;
  if(abs(left.first-right.first)<=1 && left.second && right.second){
    p.second=true;
  }
  else{
    p.second=false;
  }
  return p;
}
