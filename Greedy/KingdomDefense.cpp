int kingdomDefense(int w,int h,int n,vector<int> x,vector<int> y){
  sort(x,x+n);
  sort(y,y+n);
  
  int dx=x[i]-1,dy=y[i]-1;
  for(int i=1;i<n;i++){
    dx=max(dx,x[i]-x[i-1]-1);
    dy=max(dy,y[i]-y[i-1]-1);
  }
  dx=max(dx,w-x[n-1]);
  dy=max(dy,h-y[n-1]);
  return dx*dy;
}
