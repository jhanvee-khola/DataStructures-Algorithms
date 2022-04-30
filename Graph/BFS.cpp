vector<int> bfsGraph(int n,vector<int> adj[]){
  vector<int> bfs;
  vcetor<int> visit(n+1,0);
  
  for(int i=1;i<=n;i++){
    if(!visit[i]){
      queue<int> q;
      q.push(i);
      visit[i]=1;
      while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
          if(!visit[it]){
            q.push(it);
            visit[it]=1;
          }
        }
      }
    }
  }
  return bfs;
}
