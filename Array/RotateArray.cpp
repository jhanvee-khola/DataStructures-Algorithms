//Left Rotation

//O(n*d) time solution
void rotateByOne(int *a,int n){
  int temp=a[0];
  for(int i=0;i<n-1;i++){
    a[i]=a[i+1];
  }
  a[n-1]=temp;
}
void rotate(int *a,int n,int k){
  for(int i=0;i<k;i++){
    rotateByOne(a,n);
  }
}

//O(n) time solution
int gcd(int a,int b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
void rotate(int *a,int n,int k){
  
}
