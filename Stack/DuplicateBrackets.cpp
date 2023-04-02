bool duplicateBrackets(string s){
  stack<char> st;
  for(int i=0;i<s.length();i++){
    if(s[i]!=')'){
      st.push(s[i]);
    }
    else{
      if(st.top()=='('){
        return true;
      }
      else{
        while(st.top()!='('){
          st.pop();
        }
        st.pop();
      }
    }
  }
  return false;
}
