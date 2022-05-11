//Dijkstra's Algorithm
vector<int> shortestPath(vector<pair<int,int>> adj[],int n,int s){
  vector<int> d(n+1,INT_MAX);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  d[s]=0;
  pq.push({0,s});
  while(!pq.empty()){
    int dist=pq.top().first;
    int prev=pq.top().second;
    pq.pop();
    for(auto it:adj[prev]){
      int next=it.first;
      int nextDist=it.second;
      if(dist+nextDist<d[next]){
        d[next]=dist+nextDist;
        pq.push({d[next],next});
      }
    }
  }
  return d;
}//Dijkstra's Algorithm doesn't work in case of negative edges

//Bellman-Ford Algorithm
void shortestPath(vector<vector<int>> edg,int n,int s){
  vector<int> d(n,INT_MAX);
  d[s]=0;
  //relaxing the edges n-1 times
  for(int i=1;i<=n-1;i++){
    for(auto it: edg){
      if(d[it[0]]+it[2]<d[it[1]]){
        d[it[1]]=d[it[0]]+it[2];
      }
    }
  }
  bool f=false;
  for(auto it: edg){
    if(d[it[0]]+it[2]<d[it[1]]){
      cout<<"Negative Cycle";
      f=true;
      break;
    }
  }
  if(!f){
    for(int i=0;i<n;i++){
      cout<<i<<" "<<d[i]<<endl;
    }
  }
}//Bellman-Ford Algorithm doesn't work in case of presence of negative cycle
