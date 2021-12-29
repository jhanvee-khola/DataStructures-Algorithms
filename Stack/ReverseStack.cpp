//Reverse a stack using only 1 other stack
void tranfer(stack<int> &s1,stack<int> &s2,int k){
  for(int i=0;i<k;i++){
    s2.push(s1.top());
    s1.pop();
  }
}
void reverse(stack<int> &s1,int n){
  int x;
  stack<int> s2;
  for(int i=0;i<n;i++){
    x=s1.top();
    s1.pop();
    tranfer(s1,s2,n-i-1);
    s1.push_back(x);
    tranfer(s2,s1,n-i-1);
  }
}

//Reverse Stack Using Recursion
void insertAtBottom(stack<int> &s,int x){
  if(s.empty()){
    s.push(x);
    return;
  }
  int data=s.top();
  s.pop();
  insertAtBottom(s,x);
  s.push(data);
}
void reverse(stack<int> &s){
  if(s.empty()){
    return;
  }
  int x=s.top();
  s.pop();
  reverse(s);
  insertAtBottom(s,x);
}
