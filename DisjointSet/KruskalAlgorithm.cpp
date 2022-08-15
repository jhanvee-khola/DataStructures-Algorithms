#include<bits/stdc++.h>
using namespace std;

struct node{
  int u,v,wt;
  node(int from,int to,int w){
    u=from;
    v=to;
    wt=w;
  }
};

bool compare(node a,node b){
  return a.wt<b.wt;
}

int findParent(int n,vector<int> &parent){
  if(parent[n]==n){
    return n;
  }
  return parent[n]=findParent(parent[n],parent);
}

void unionNode(int u,int v,vector<int> &parent,vector<int> &rank){
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

int main(){
  int n,m; //n->nodes m->edges
  vector<node> edges;
  for(int i=0;i<m;i++){
    int to,from,w;
    cin>>from>>to>>w;
    node n(from,to,w);
    edges.push_back(n);
  }
  sort(edges.begin(),edges.end(),compare);
  vector<int> parent(n);
  vector<int> rank(n);
  for(int i=1;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
  int cost=0;
  vector<pair<int,int>> mst;
  for(auto it:edges){
    if(findParent(it.u,parent)!=findParent(it.v,parent)){
      cost+=it.wt;
      mst.push_back({it.u,it.v});
      unionNode(it.u,it.v,parent,rank);
    }
  }
  //cost stores the total cost of mst and mst vector stores all the edges included in the mst
  return 0;
}
