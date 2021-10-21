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
	        if(j!=0){
	            a[i][j]+=a[i-1][j];
	        }
	        
	    }
	}
	
	for(int i=n-1;i>=0;i--){
	    for(int j=m-1;j>=0;j--){
	        
	    }
	}
	
	return 0;
}
