bool compare(pair<int,int> p,pair<int,int> q){
  return p.second<q.second;
}
int activitySelection(vector<pair<int,int>> a){
  sort(a.begin(),a.end(),compare);
  int ans=1,fin=a[0].second;
  for(int i=1;i<a.size();i++){
    if(v[i].first>=fin){
      ans++;
      fin=v[i].second;
    }
  }
  return ans;
}
