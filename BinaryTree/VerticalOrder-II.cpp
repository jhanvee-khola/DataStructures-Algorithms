vector<vector<int>> verticalOrderTraversal(TreeNode *root){
    priority_queue<pair<TreeNode*,int>> pQ;
    priority_queue<pair<TreeNode*,int>> cQ;
    map<int,vector<int>> mp;
    int mini=0,maxi=0;
    pQ.push({root,0});
    while(!pQ.empty() || !cQ.empty()){
        if(pQ.empty()){
            priority_queue<pair<TreeNode*,int>> tempQ=cQ;
            cQ=pQ;
            pQ=tempQ;
        }
        TreeNode *node=pQ.top().first;
        int hz=pQ.top().second;
        mini=min(mini,hz);
        maxi=max(maxi,hz);
        pQ.pop();
        if(mp.find(hz)==mp.end()){
            vector<int> temp;
            mp.insert({hz,temp});
        }
        mp[hz].push_back(node->val);
        if(node->left){
            cQ.push({node->left,hz-1});
        }
        if(node->right){
            cQ.push({node->right,hz+1});
        }
    }
    vector<vector<int>> ans;
    for(int i=mini;i<=maxi;i++){
        ans.push_back(mp[i]);
    }
    return ans;
}
