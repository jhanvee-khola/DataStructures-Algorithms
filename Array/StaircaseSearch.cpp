#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,k;
  cin>>n>>m>>k;
  int a[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  int i=0,j=m-1;
  while(i<n && j>=0){
      if(a[i][j]<k){
          i++;
      }
      else if(a[i][j]>k){
          j--;
      }
      else{
          cout<<i<<", "<<j;
          break;
      }
  }
  return 0;
}
