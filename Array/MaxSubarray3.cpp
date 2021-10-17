#include<bits/stdc++.h>
using namespace srd;

int main(){
  int n;
  cin>>n;
  int a[n];
  
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  //1. Kadane's Algorithm
  int csum=0,ans=0;
  for(int i=0;i<n;i++){
    csum+=a[i];
    if(csum<0){
      csum=0;
    }
    ans=max(ans,csum);
  }
  //This doesn't work for the case when all the elements of the array are negative
  
  //2. 2nd Method
  int csum1=a[0],ans1=a[0];
  for(int i=0;i<n;i++){
    csum1=max(a[i],csum1+a[i]);
    ans1=max(ans1,csum1);
  }
  //Here ans1 gives the maximum sum even when all elements of the array are negative
  return 0;
}
