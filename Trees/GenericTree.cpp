class Node{
  public:
  int val;
  vector<Node*> children;
  
  Node(){
    val=0;
    vector<Node*> c;
    children=c;
  }
  Node(int v){
    val=v;
    vector<Node*> c;
    children=c;
  }
};

//Given the euler path of a generic tree construct the tree from it
Node* constructTree(vector<int> eulerPath){
  stack<Node*> s;
  Node *root;
  for(int i=0;i<eulerPath.size();i++){
    if(eulerPath[i]==-1){
      s.pop();
    }
    else{
      Node *n=new Node(eulerPath[i]);
      if(s.empty()){
        root=n;
      }
      else{
        s.top()->children.push_back(n);
      }
      s.push(n);
    }
  }
  return root;
}

//Given a generic tree, display its euler tour
void display(Node *root){
  cout<<root->val<<" -> ";
  for(auto child:root->children){
    cout<<child->val<<" ";
  }
  cout<<"."<<endl;
  for(auto child:root->children){
    display(child);
  }
}

//Given a generic tree, give the height of the tree i.e. no. of edges that the deepest node is away from the root node
int height(Node *root){
  int ans=-1;
  for(auto child:root->children){
    ans=max(ans,height(child));
  }
  ans+=1;
  return ans;
}

//level order traversal -> same as binary tree
