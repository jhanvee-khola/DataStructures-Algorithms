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
}
