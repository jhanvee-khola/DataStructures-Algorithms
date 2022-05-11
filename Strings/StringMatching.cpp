//Naive string matching
void search(string s,string p){
  int n=s.length(),m=p.length();
  for(int i=0;i<=n-m;i++){
    int j;
    for(j=0;j<m;j++){
      if(s[i+j]!=p[j]){
        break;
      }
      if(j==m){
        cout<<i<<endl;
      }
    }
  }
}

//KMP(Knuth-Morris-Pratt) Algorithm
void search(string s,string p){
  int n=s.length(),m=p.length();
  
}
