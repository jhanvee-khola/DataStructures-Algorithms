//Given a string s1 and a string s2, check whether s2 is a rotation of s1

//Method 1
bool isRotation(string s,string t){
  if(s.length()!=t.length()){
    return false;
  }
  string sRep=s+s;
  //Now if t is a substring of sRep then t is a rotation of s
  return sRep.find(t)!=string::npos;
}

//Method 2
bool isRotation(string s,string t){
  if(s.length()!=t.length()){
    return false;
  }
  queue<char> q1;
  for(int i=0;i<s.length();i++){
    q1.push(s[i]);
  }
  queue<char> q2;
  for(int i=0;i<t.length();i++){
    q2.push(t[i]);
  }
  int l=t.length();
  while(t--){
    char c=q2.front();
    q2.pop();
    q2.push(c);
    if(q1==q2){
      return true;
    }
  }
  return false;
}
