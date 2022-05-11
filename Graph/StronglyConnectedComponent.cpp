//Kosaraju's Algorithm
void dfsTopo(int node,vector<int> adj[],vector<int> visit,stack<int> s){
  visit[node]=1;
  for(auto it: adj[node]){
    if(!visit[it]){
      dfsTopo(it,adj,visit,s);
    }
  }
  s.push(node);
}
void scc(vector<int> adj,int n){
  //1) Topological Sorting
  vector<int> visit(n+1,0);
  stack<int> topo;
  for(int i=1;i<=n;i++){
    if(!visit[i]){
      dfsTopo(i,adj,visit,topo);
    }
  }
  
  //2)Transpose of Graph
  
}
