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
  //--------------------------------------------------------------------------
  
  //Optimised Approach - O(n^2) time and O(n) space solution
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
  //l and r give the required subarray and ans stores the maximum sum
  //--------------------------------------------------------------------------
  
  //Optimised Approach - O(n) time and O(1) space solution
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
