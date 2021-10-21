#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[n][m];
	
	//input
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        cin>>a[i][j];
	    }
	}
  
  //Brute force would be simply iterate over the elements in the given submatrix for each query and find the sum 
  //so worst case time complexity could be q*m*n
  
  //Optimised Approach
	//Pre-processing to make a prefix sum matrix
	//column-wise
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(j!=0){
	            a[i][j]+=a[i][j-1];
	        }
	    }
	}
	//row-wise
	for(int j=0;j<m;j++){
	    for(int i=0;i<n;i++){
	        if(i!=0){
	            a[i][j]+=a[i-1][j];
	        }
	    }
	}
	
	int q;
	cin>>q;
	while(q--){
	    int x1,x2,y1,y2;
	    cin>>x1>>y1>>x2>>y2;
	    int ans=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
	    cout<<ans<<endl;
	}
	
	return 0;
}
