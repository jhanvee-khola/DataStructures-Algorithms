//Given an array of positive numbers and a positive number k, find the length of the smallest contiguous subarray whose sum is greater than or equal to k

int minSubarray(int a[],int n,int k){
  int start=0,wSum=0,ans=INT_MAX;
  for(int end=0;end<n;end++){
    wSum+=a[end];
    while(wSum>=k){
      ans=min(ans,end-start+1);
      wSum-=a[start];
      start++;
    }
  }
  return ans==INT_MAX?0:ans;
}
