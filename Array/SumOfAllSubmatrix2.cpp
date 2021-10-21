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
	int b[n][m]={0};
	
	//column-wise prefix sum
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(j==0){
	            b[i][j]=a[i][j];
	        }
	        else{
	            b[i][j]=b[i][j-1]+a[i][j];
	        }
	    }
	}
	//row-wise prefix sum
	for(int j=0;j<m;j++){
	    for(int i=0;i<n;i++){
	        b[i][j]+=b[i-1][j];
	    }
	}
	//can also be done in O(1) space by modifying the matrix 'a' in-place.
	int ans=0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        for(int k=i;k<n;k++){
	            for(int l=j;l<m;l++){
	                ans+=b[k][l]-b[i][j]-b[i-1][l]-b[k][j-1]+b[i-1][j-1];
	            }
	        }
	    }
	}
	return 0;
}
