//Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, 
//find the length of the longest substring having the same letters after replacement.

int longestAfterK(string s,int k){
  int n=s.length();
  int start=0,ans=0,maxCount=0;
  for(int end=0;end<n;end++){
    freq[s[end]]++;
    maxCount=max(maxCount,freq[s[end]]);
    if(end-start+1-maxCount>k){
      freq[s[start]]--;
      start++;
    }
    ans=max(ans,end-start+1);
  }
}
