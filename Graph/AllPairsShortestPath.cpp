// Floyd Warshall Algorithm
vector<vector<int>> allPairShortestPath(vector<vector<int>> edges,int n){
  vector<vector<int>> ans(n,vector<int>(n,INT_MAX));
  for(int i=0;i<edges.size();i++){
    int u=edges[i][0];
    int v=edges[i][1];
    int wt=edges[i][2];
    ans[u][v]=wt;
  }
  for(int i=0;i<n;i++){
    ans[i][i]=0;
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(ans[i][j]>(ans[i][k]+ans[k][j])){
          ans[i][j]=ans[i][k]+ans[k][j];
        }
      }
    }
  }
  return ans;
}
