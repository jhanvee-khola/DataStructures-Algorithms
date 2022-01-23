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

node* Build(int pre[],int in[],int s,int e){
  static int i=0;
  if(s>e){
    return NULL:
  }
  node* root=new node(pre[i]);
  int index=-1;
  for(int j=s;j<=e;j++){
    if(in[j]==pre[i]){
      index=j;
      break;
    }
  }
  i++;
  root->left=Build(pre,in,s,index-1);
  root->right=Build(pre,in,index+1,e);
  return root;
}
