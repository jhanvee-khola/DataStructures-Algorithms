bool isSafe(vector<string> pos,int x,int y,int n){
    //column check
    for(int i=0;i<x;i++){
        if(pos[i][y]=='Q'){
            return false;
        }
    }
    //north-west diagonal
    int i=x-1,j=y-1;
    while(i>=0 && j>=0){
        if(pos[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    //north-east diagonal
    i=x-1,j=y+1;
    while(i>=0 && j<n){
        if(pos[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

//all-solutions
void nQueen(vector<vector<string>> &ans,vector<string> pos,int row,int n){
    if(row==n){
        ans.push_back(pos);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(pos,row,col,n)){
            pos[row][col]='Q';
            nQueen(ans,pos,row+1,n);
            pos[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> pos;
    string s="";
    for(int i=0;i<n;i++){
        s+=".";
    }
    pos=vector<string>(n,s);
    nQueen(ans,pos,0,n);
    return ans;
}
