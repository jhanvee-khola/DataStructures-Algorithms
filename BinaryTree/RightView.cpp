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

void rightView(node* root,int cl,int ml){
  //initial values of cl and ml would be 0 and -1 respectively
  if(root==NULL){
    return;
  }
  if(cLevel>mLevel){
    cout<<root->data<<" ";
    ml=cl;
  }
  rightView(root->right,cl+1,ml);
  rigthView(root->left,cl+1,ml);
}
