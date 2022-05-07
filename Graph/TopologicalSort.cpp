//Using DFS
void dfsTopo(int node,vector<int> adj[],vector<int> visit,stack<int> s){
  visit[node]=1;
  for(auto it: adj[node]){
    if(!visit[it]){
      dfsTopo(it,adj,visit,s);
    }
  }
  s.push(node);
}

vector<int> topologicalSort(int n,vector<int> adj[]){
  vector<int> visit(n+1,0);
  stack<int> topo;
  
  for(int i=1;i<=n;i++){
    if(!visit[i]){
      dfsTopo(i,adj,visit,topo);
    }
  }
  vector<int> ans;
  while(!topo.empty()){
    ans.push_back(topo.top());
    topo.pop();
  }
  return ans;
}

//Using BFS (Kahn's Algorithm)
vector<int> topologicalSort(int n,vector<int> adj[]){
  vector<int> inDegree(n+1,0);
  vector<int> ans;
  for(int i=1;i<=n;i++){
    for(auto it:adj[i]){
      inDegree[it]++;
    }
  }
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(inDegree[i]==0){
      q.push(i);
    }
  }
  while(!q.empty()){
    int node=q.front();
    ans.push_back(node);
    q.pop();
    for(auto it:adj[node]){
      inDegree[it]--;
      if(inDegree[it]==0){
        q.push(it);
      }
    }
  }
  return ans;
}
