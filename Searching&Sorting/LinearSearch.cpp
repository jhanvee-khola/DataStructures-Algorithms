#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int k;
  cin>>k;
  bool b=false;
  for(int i=0;i<n;i++){
    if(a[i]==k){
      cout<<i;
      b=true;
      break;
    }
  }
  if(!b){
    cout<<"Element not found";
  }
  return 0;
}
