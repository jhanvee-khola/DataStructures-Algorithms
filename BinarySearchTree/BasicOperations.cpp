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

node* deletion(node* root,int k){
  if(root==NULL){
    return NULL;
  }
  else if(k<root->data){
    root->left=deletion(root->left,k);
    return root;
  }
  else if(k>root->data){
    root->right=deletion(root->right,k);
    return root;
  }
  else{
    if(root->left==NULL && root->right==NULL){
      delete root;
      return NULL;
    }
    else if(root->left!=NULL && root->right==NULL){
      node* temp=root->left;
      delete root;
      return temp;
    }
    else if(root->left==NULL && root->right!=NULL){
      node* temp=root->right;
      delete root;
      return temp;
    }
    else{
      //finding maximum in left subtree
      node* temp=root->left;
      while(temp->right!=NULL){
        temp=temp->right;
      }
      root->data=temp->data;
      root->left=deletion(root->left,temp->data);
      return root;
      //minimum in right subtree can also be used
    }
  }
}
