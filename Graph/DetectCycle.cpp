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
