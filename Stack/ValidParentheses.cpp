bool isValid(char *s){
  stack<char> s1;
  for(int i=0;s[i]!='\0';i++){
    char c=s[i];
    if(c=='(' || c=='[' || c=='{'){
      s1.push(c);
    }
    else{
      if(s1.empty()){
        return false;
      }
      char top=s1.top();
      if(c==')' && top=='(' || c=='}' && top=='{' || c==']' && top=='['){
        s1.pop();
      }
      else{
        return false;
      }
    }
  }
  return s1.empty();
}
