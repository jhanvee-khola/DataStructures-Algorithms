bool compare(pair<string,int> p,pair<string,int> q){
  return p.second<q.second;
}
//Method 1 O(nlogn) time
int biasedRanks(vector<pair<string,int>> v){
  //using incuilt sort function/merge/quick sort
  sort(v.begin(),v.end(),compare);
  int ans=0,lastR=v[0].second;
  for(int i=1;i<v.size();i++){
    ans+=abs(lastR-v[i].second);
    lastR++;
  }
  return ans;
}

//Method 2 O(n) time
int biasedRanks(vector<pair<string,int>> v){
  //using counting sort type of algorithm
  int arr[100000]={0};
  for(int i=0;i<v.size();i++){
    arr[v[i].second]++;
  }
  int lastR=1,ans=0;
  for(int i=0;i<v.size();i++){
    while(arr[i]){
      ans+=abs(lastR-i);
      lastR++;
      arr[i]--;
    }
  }
  return ans;
}
