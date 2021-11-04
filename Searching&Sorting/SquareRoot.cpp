#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  //finding the floor value of the square-root
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
  //for floating point answer
  int p;//precision
  cin>>p;
  float inc=0.1;
  for(int i=0;i<p;i++){
    while(ans*ans<=n){
      ans+=inc;
    }
    //comes out of the loop when overshot the value
    ans-=inc;
    inc/=10;
  }
  return 0;
}
