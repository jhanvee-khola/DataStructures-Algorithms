#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int s=0,e=n,ans=0;
  while(s<=e){
    int mid=(s+e)/2;
    if(mid*mid==n){
      ans=mid;
      break;
    }
    else if(mid*mid<n){
      ans=mid;
      s=mid+1;
    }
    else{
      e=n-1;
    }  
  }
  return 0;
}
