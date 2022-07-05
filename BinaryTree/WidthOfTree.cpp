void horizontalLevels(TreeNode *root,int hzlevel,int &minWidth,int &maxWidth){
    if(!root){
        return;
    }
    minWidth=min(minWidth,hzlevel);
    maxWidth=max(maxWidth,hzlevel);
    horizontalLevels(root->left,hzlevel-1,minWidth,maxWidth);
    horizontalLevels(root->right,hzlevel+1,minWidth,maxWidth);
}
int width(TreeNode *root){
    if(!root){
        return 0;
    }
    int minWidth=0;
    int maxWidth=0;
    horizontalLevels(root,0,minWidth,maxWidth);
    return maxWidth-minWidth+1;
}
