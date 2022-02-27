#include<bits/stdc++.h>

bool compare(pair<int,int> p,pair<int,int> q){
  return p.first?q.first;
}

int expedition(int l,int n,int p,vector<pair<int,int> f){
  priority_queue<int> pq;
  sort(f.begin(),f.end(),compare);
  for(int i=0;i<n;i++){
    f[i].first=l-f[i].first;
  }
  int i=0,prev=0,ans=0;
  while(i<n){
    if(p>=f[i].first-prev){
      p-=(f[i].first-prev);
      pq.push(f[i].second);
      prev=f[i].first;
    }
    else{
      if(pq.empty()){
        return -1;
      }
      else{
        p+=pq.top();
        pq.pop();
        ans++;
        continue;
      }
    }
    i++;
  }
  if(p>=l-f[n-1].first){
    return ans;
  }
  //else
  while(p<l-f[n-1].first){
    if(pq.empty()){
      return -1;
    }
    p+=pq.top();
    pq.pop();
    ans++;
  }
  return ans;
}
