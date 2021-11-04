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
  int s=0,e=n-1,ans=-1;
  while(s<=e){
    int mid=(s+e)/2;
    if(a[mid]==k){
      ans=mid;
      break;
    }
    else if(a[s]<=a[mid]){
      if(key>=a[s] and key<=a[mid]){
        e=mid-1;
      }
      else{
        s=mid+1;
      }
    }
    else{
      if(key<=a[e] and key>=a[mid]){
        s=mid+1;
      }
      else{
        e=mid-1;
      }
    }
  }
  return 0;
}
