#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>m>>n;
  int a[m][n];
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  
  int startR=0,endR=m-1,startC=0,endC=n-1;
  
  while(startR<=endR && startC<=endC){
      for(int i=startC;i<=endC;i++){
          cout<<a[startR][i]<<" ";
      }
      startR++;
      for(int i=startR;i<=endR;i++){
          cout<<a[i][endC]<<" ";
      }
      endC--;
      if(startR<endR){
        for(int i=endC;i>=startC;i--){
          cout<<a[endR][i]<<" ";
        }
        endR--;  
      }
      if(startC<endC){
        for(int i=endR;i>=startR;i--){
          cout<<a[i][startC]<<" ";
        }  
        startC++;
      }
      
  }
  return 0;
}
