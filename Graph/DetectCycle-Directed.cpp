//Using DFS
bool dfsCheck(int node,vector<int> adj[],vector<int> visit,vector<int> dfsVisit){
  visit[node]=1;
  dfsVisit[node]=1;
  for(auto it: adj[node]){
    if(!visit[it]){
      if(dfsCheck(it,adj,visit,dfsVisit)){
        return true;
      }
    }
    else if(visit[it] && dfsVisit[it]){
      return true;
    }
  }
  dfsVisit[node]=0;
  return false;
}
bool detectCycle(int n,vector<int> adj[]){
  vector<int> visit(n+1,0);
  vector<int> dsfVisit(n+1,0);
  
  for(int i=1;i<=n;i++){
    if(!visit[i]){
      if(dfsCheck(i,adj,visit,dfsVisit)){
        return true;
      }
    }
  }
  return false;
}

//Using BFS (Kahn's Algorithm)
bool detectCycle(int n,vector<int> adj[]){
  vector<int> inDegree(n+1,0);
  for(int i=1;i<=n;i++){
    for(auto it:adj[i]){
      inDegree[it]++;
    }
  }
  queue<int> q;
  int count=0;
  for(int i=1;i<=n;i++){
    if(inDegree[i]==0){
      q.push(i);
    }
  }
  while(!q.empty()){
    int node=q.front();
    q.pop();
    count++;
    for(auto it:adj[node]){
      inDegree[it]--;
      if(inDegree[it]==0){
        q.push(it);
      }
    }
  }
  if(count==n){
    return false;
  }
  return true;
}
