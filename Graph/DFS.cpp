void dfs(int node,vector<int> visit,vector<int> adj[],vector<int> dfsAns){
  dfsAns.push_back(node);
  visit[node]=1;
  for(auto it: adj[node]){
    if(!visit[it]){
      dfs(it,visit,adj,dfsAns);
    }
  }
}

vector<int> dfsGraph(int n,vector<int> adj[]){
  vector<int> dfsAns;
  vector<int> visit(n+1,0);
  
  for(int i=1;i<=n;i++){
    if(!visit[i]){
      dfs(i,visit,adj,dfsAns);
    }
  }
  return dfsAns;
}
