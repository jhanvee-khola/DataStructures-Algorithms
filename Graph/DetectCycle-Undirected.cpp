//Using DFS
bool cycleDFS(int node,vector<int> adj[],vector<int> visit,int parent){
  visit[node]=1;
  for(auto it:adj[node]){
    if(!visit[it]){
      if(cycleDFS(it,adj,visit,node)){
        return true;
      }
    }
    else if(it!=parent && visit[it]){
      return true;
    }
  }
  return false;
}
bool cycleDetection(int n,vector<int> adj[]){
  vector<int> visit(n+1,0);
  for(int i=1;i<=n;i++){
    if(!visit[i]){
      if(cycleDFS(i,adj,visit,-1)){
        return true;
      }
    }
  }
  return false;
}

//Using BFS
bool cycleDetection(int n,vector<int> adj[]){
  vector<int> visit(n+1,0);
  for(int i=1;i<=n;i++){
    if(!visit[i]){
      queue<pair<int,int>> q;
      q.push({i,-1});
      visit[i]=1;
      while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it: adj[node]){
          if(!visit[it]){
            q.push({it,node});
            visit[it]=1;
          }
          else if(it!=parent && visit[it]){
            return true;
          }
        }
      }
    }
  }
  return false;
}
