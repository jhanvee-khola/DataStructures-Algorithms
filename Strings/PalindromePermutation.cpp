//Given a string, write a function to check if it is a permutation of a palindrome

bool palindromePermutation(string s){
  map<char,int> freq;
  for(int i=0;i<s.length();i++){
    freq[s[i]]++;
  }
  int count=0;
  for(auto ch:freq){
    if(ch.second%2!=0){
      count++;
    }
  }
  if(count>1) return false;
  
  return true;
}
