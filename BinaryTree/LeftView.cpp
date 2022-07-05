vector<int> leftView(TreeNode *root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    queue<TreeNode*> levels;
    levels.push(root);
    int l=0;
    while(!levels.empty()){
        ans.push_back(levels.front()->val);
        int s=levels.size();
        while(s--){
            TreeNode *f=levels.front();
            levels.pop();
            if(f->left){
                levels.push(f->left);
            }
            if(f->right){
                levels.push(f->right);
            }
        }
    }
    return ans;
}
