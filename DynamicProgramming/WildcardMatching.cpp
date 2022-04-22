//recursive approach
bool isMatch(string s,string t,int n,int m){
  if(s==0){
  
  }
  if(s[n-1]==t[m-1] || t[m-1]=='?'){
    return isMatch(s,t,n-1,m-1);
  }
  if(t[m-1]=='*'){
    isMatch(s,t,n,m-1)||isMatch(s,t,n-1,m);
  }
  return false;
}
