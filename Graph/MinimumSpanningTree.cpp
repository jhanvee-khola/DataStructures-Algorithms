//Prim's Algorithm
void primMST(vector<pair<int,int>> adj[],int n){
  int key[n];
  int parent[n];
  bool mst[n];
  
  for(int i=0;i<n;i++){
    key[i]=INT_MAX;
    parent[i]=-1;
    mst[i]=false;
  }
  key[0]=0;
  
  //mst contains n-1 edges
  for(int i=0;i<n-1;i++){
    int u=INT_MAX,mini=INT_MAX;
    for(int v=0;v<n;v++){
      if(mst[v]==false && key[v]<mini){
        mini=key[v];
        u=v;
      }
    }
    mst[u]=true;
    for(auto it:adj[u]){
      int v=it.first;
      int w=it.second;
      if(mst[v]==false && w<key[v]){
        parent[v]=u;
        key[v]=w;
      }
    }
  }
  
  for(int i=1;i<n;i++){
    cout<<parent[i]<<"-"<<i<<endl;
  }
}

//Optimization
void primMST2(vector<pair<int,int>> adj[],int n){
  int key[n];
  int parent[n];
  bool mst[n];
  
  for(int i=0;i<n;i++){
    key[i]=INT_MAX;
    parent[i]=-1;
    mst[i]=false;
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  key[0]=0;
  pq.push({0,0});
  while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();
    if(mst[u]=true){
      continue;
    }
    mst[u]=true;
    for(auto it:adj[u]){
      int v=it.first;
      int w=it.second;
      if(mst[v]==false && w<key[v]){
        parent[v]=u;
        key[v]=w;
        pq.push({key[v],v});
      }
    }
  }
  for(int i=1;i<n;i++){
    cout<<parent[i]<<"-"<<i<<endl;
  }
}

//Another algorithm to find mst is Kruskal's algorithm that uses disjoint set. Included in Disjoint Set directory
