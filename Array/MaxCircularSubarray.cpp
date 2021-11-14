#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int tmax=0,smax=INT_MIN,tmin=0,smin=INT_MAX,tsum=0;
  for(int i=0;i<n;i++){
    tmax+=a[i];
    tmin+=a[i];
    tsum+=a[i];
    smax=max(smax,tmax);
    smin=min(smin,tmin);
    if(tmax<0){
      tmax=0;
    }
    if(tmin>0){
      tmin=0;
    }
  }
  int ans;
  if(tsum==smin){
    ans=smax;
    //this the case where all elements are negative
  }
  else{
    ans=tsum-smin;
    //since maximum subarray sum with wrap around property is total sum of array minus the minimum subarray sum without the wrap around property
  }
  return 0;
}
