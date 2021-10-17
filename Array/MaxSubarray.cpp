#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  
  //Brute Force approach
  int ans=INT_MIN,l=0,r=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int csum=0;
      for(int k=i;k<j;k++){
        csum+=a[k];
      }
      if(ans<csum){
        ans=csum;
        l=i;
        r=j;
      }
    }
  }
  //l and r give the required subarray and ans stores the maximum sum
  return 0;
}
