#include<bits/stdc++.h>
using namespace std;

int main(){
  //Brute Force would be count and store the total no. of 0s, 1s and 2s in the array then rewrite the array with counts accordingly
  
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int low=0,mid=0,high=n-1;
  while(mid<=high){
    if(a[mid]==0){
      swap(a[mid],a[low]);
      mid++;
      low++;
    }
    else if(a[mid]==2){
      swap(a[mid],a[high]);
      high--;
    }
    else{
      mid++;
    }
  }
  for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
  }
  return 0;
}
