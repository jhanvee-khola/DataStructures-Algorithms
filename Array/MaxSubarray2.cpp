#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  
  int sum_a[n]={a[0]};
  for(int i=1;i<n;i++){
    sum_a[i]=sum_a[i-1]+a[i];
  }
  int ans=INT_MIN,l=0,r=0;
  
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int csum=sum_a[j]-sum_a[i-1];
      if(ans<csum){
        ans=csum;
        l=i;
        r=j;
      }
    }
  }
  
  //l and r give the required subarray and ans the maximum sum
  return 0;
}
