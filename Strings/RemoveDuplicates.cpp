#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  char s[n];
  cin>>s;
  int j=0;
  for(int i=1;i<n;i++){
    if(s[i]!=s[j]){
      j++;
      s[j]=s[i];
    }
  }
  s[i]='\0';      
  return 0;
}
