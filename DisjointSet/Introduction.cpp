int parent[10000];
int rank[10000];

void makeSet(){
  for(int i=1;i<=n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}

int findParent(int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node]=findParent(parent[node]);
}
void union(int u,int v){
  u=parent[u];
  v=parent[v];
  
  if(rank[u]<rank[v]){
    parent[u]=v;
  }
  else if(rank[v]<rank[u]){
    parent[v]=u;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}
