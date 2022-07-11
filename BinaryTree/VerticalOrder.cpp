vector<vector<int>> verticalOrderTraversal(TreeNode *root){
    int mini=0,maxi=0;
    map<int,vector<int>> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            TreeNode* node=q.front().first;
            int hz=q.front().second;
            maxi=max(maxi,hz);
            mini=min(mini,hz);
            q.pop();
            if(mp.find(hz)==mp.end()){
                vector<int> levelNodes;
                mp.insert({hz,levelNodes});
            }
            mp[hz].push_back(node->val);
            if(node->left){
                q.push({node->left,hz-1});
            }
            if(node->right){
                q.push({node->right,hz+1});
            }
        }
    }
    vector<vector<int>> ans;
    for(int i=mini;i<=maxi;i++){
        ans.push_back(mp[i]);
    }
    return ans;
}
