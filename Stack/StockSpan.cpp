void span(int a[],int ans[],int n){
  stack<int> s;
  ans[0]=1;
  s.push(0);
  for(int i=1;i<n;i++){
    while(!s.empty() && a[s.top()]<=a[i]){
      s.pop();
    }
    if(!s.empty()){
      ans[i]=i-s.top();
    }
    else{
      ans[i]=i+1;
    }
    s.push(i);
  }
}
