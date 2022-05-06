//using BFS
bool checkBipartite(int n,vector<int> adj[]){
  vector<int> color(n+1,-1);
  for(int i=1;i<=n;i++){
    if(color[i]==-1){
      queue<int> q;
      q.push(i);
      color[i]=0;
      while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
          if(color[it]==-1){
            q.push(it);
            color[it]=1-color[node];
          }
          else if(color[it]==color[node]){
            return false;
          }
        }
      }
    }
  }
  return true;
}

//using DFS
bool dfsCheck(int node,vector<int> color,vector<int> adj[]){
  if(color[node]==-1){
    color[node]=0;
  }
  for(auto it:adj[node]){
    if(color[it]==-1){
      color[it]=1-color[node];
      if(!dfsCheck(it,color,adj)){
        return false;
      }
    }
    else if(color[it]==color[node]){
      return false;
    }
  }
  return true;
}
bool checkBipartite(int n,vector<int> adj[]){
  vector<int> color(n+1,-1);
  for(int i=1;i<=n;i++){
    if(color[i]==-1){
      if(!dfsCheck(it,color,adj)){
        return false;
      }
    }
  }
  return true;
}
