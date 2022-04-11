//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

//recursive approach
int maxPoints(int day,int last,int a[][3]){
  if(day==0){
    int maxi=0;
    for(int i=0;i<=2;i++){
      if(i!=last){
        maxi=max(maxi,a[0][i]);
      }
    }
    return maxi;
  }
  int maxi=0;
  for(int i=0;i<=2;i++){
    if(i!=last){
      int points=a[day][i]+maxPoints(day-1,i);
      maxi=max(maxi,points);
    }
  }
  return maxi;
}

//top-down dp
int maxPoints(int day,int last,int a[][3],int dp[][4]){
  if(day==0){
    int maxi=0;
    for(int i=0;i<=2;i++){
      if(i!=last){
        maxi=max(maxi,a[0][i]);
      }
    }
    return maxi;
  }
  if(dp[day][last]!=-1){
    return dp[day][last];
  }
  int maxi=0;
  for(int i=0;i<=2;i++){
    if(i!=last){
      int points=a[day][i]+maxPoints(day-1,i);
      maxi=max(maxi,points);
    }
  }
  return dp[day][last]=maxi;
}

//bottom-up dp - 35:32
int maxPoints(int n,int a[][3]){
  int dp[n][4];
  dp[0][0]=max(a[1],a[2]);
  dp[0][1]=max(a[0],a[2]);
  dp[0][2]=max(a[1],a[3]);
  dp[0][3]=max(a[0],max(a[1],a[2]));
  for(int i=1;i<n;i++){
    for(int j=0;j<4;j++)
    int maxi=0;
    for(int k=0;k<3;k++){
      if(k!=j){
        int pt=a[i][j]+dp[][];
        
      }
      
    }
  }
  
}

//space-optimization
int maxPoints(int n,int a[][3]){
  int dp[4];
  for(int i=1;i<n;i++){
    
  }
}
