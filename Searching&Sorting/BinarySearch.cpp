#include<iostream>
using namepsace std;

int binarySearch(int a[],int s,int e,int k){
  while(s<=e){
    int mid=s+(e-s)/2;
    if(a[mid]==k){
      return mid;
    }
    else if(a[mid]<k){
      return binarySearch(a,mid+1,e,k);
    }
    else{
      return binarySearch(a,s,mid-1,k);
    }
  }
  return -1;//if not found
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int k;
  cin>>k;
  cout<<binarySearch(a,0,n;k);
  return 0;
}
