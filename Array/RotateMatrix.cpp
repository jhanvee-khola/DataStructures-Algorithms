#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    int s=0,e=n-1;
    while(s<e){
      swap(a[i][s],a[i][e]);
      s++;
      e--;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i<j){
        swap(a[i][j],a[j][i]);
      }
    }
  }
  return 0;
}
