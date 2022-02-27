//Method 1
int loadBalance(int a[],int n){
  int total=0;
  for(int i=0;i<n;i++){
    total+=a[i];
  }
  if(total%n!=0){
    return -1;
  }
  total/=n;
  int ans=0;
  for(int i=0;i<n-1;i++){
    int b=0;
    for(int j=0;j<=i;j++){
      b+=a[j];
    }
    int t=abs(total*(i+1)-b);
    ans=max(ans,t);
  }
  return ans;
}

//Method 2
int loadBalance(int a[],int n){
  int load=0;
  for(int i=0;i<n;i++){
    load+=a[i];
  }
  if(load%n!=0){
    return -1;
  }
  load/=n;
  int diff=0,ans=0;
  for(int i=0;i<n;i++){
    diff+=(a[i]-load);
    ans=max(ans,abs(diff));
  }
  return ans;
}
