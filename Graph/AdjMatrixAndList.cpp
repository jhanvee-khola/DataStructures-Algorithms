int main(){
  int n,e;//no. of nodes and edges
  cin>>n>>e;
  
  //Adjacency Matrix
  int adjm[n+1][n+1];
  for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adjm[u][v]=1;
    adjm[v][u]=1;//no in directed graph
  }
  //in case of weighted graph update matrix with weight
  
  //Adjacency List
  vector<int> adjl[n+1];
  for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);//no in directed graph
  }
  //in case of weighted graph data type of list would be vector<pair<int,int>>   
  return 0;
}
