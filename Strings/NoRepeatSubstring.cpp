//Given a string, find the length of the longest substring which has no repeating characters.

int noRepeat(string s){
  int n=s.length();
  int start=0,ans=0;
  unordered_map<char,int> mp;
  for(int end=0;end<n;end++){
    if(mp.find(s[end])!=mp.end()){
      start=max(start,mp[s[end]]+1);
    }
    mp[s[end]]=end;
    ans=max(ans,end-start+1);
  }
  return ans;
}
