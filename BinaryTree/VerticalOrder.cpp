vector<vector<int>> verticalOrderTraversal(TreeNode *root){
  int mini=0,maxi=0;
  map<int,vector<int>> mp;
  queue<pair<TreeNode*,int>> q;
  q.push({root,0});
  while(!q.empty()){
    ans[]=;
    int s=q.size();
    for(int i=0;i<s;i++){
      TreeeNode* node=q.front().first;
      int hz=q.front().second;
      q.pop();
      if(mp.find(hz)==mp.end()){
        mp.insert({hz,})
      }
      if(node->left){
        q.push(node->left,hz-1);
      }
      if(node->right){
        q.push(node->right,hz+1);
      }
    }
  }
  
  vector<vector<int>> ans;
}
