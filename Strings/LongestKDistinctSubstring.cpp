//Given a string, find the length of the longest substring in it with no more than K distinct characters.

int kDistinct(string s,int k){
  int n=s.length();
  int start=0,wFreq=0,ans=0;
  unordered_map<char,int> freq;
  for(int end=0;end<n;end++){
    freq[s[end]]++;
    while(freq.size()>k){
      freq[s[start]]--;
      if(freq[s[start]]==0){
        freq.erase(s[start]);
      }
      start++;
    }
    ans=max(ans,end-start+1);
  }
  return ans;
}
