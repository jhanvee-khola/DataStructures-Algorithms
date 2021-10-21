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
	//Pre-processing to make a suffix sum matrix since we want the bottom-right corner to be included
	//column-wise
	for(int i=n-1;i>=0;i--){
	    for(int j=m-2;j>=0;j--){
	        a[i][j]+=a[i][j+1];
	    }
	}
	//row-wise
	for(int j=m-1;j>=0;j--){
	    for(int i=n-2;i>=0;i--){
	        a[i][j]+=a[i+1][j];
	    }
	}
	int maxSum=INT_MIN;
	for(int i=n-1;i>=0;i--){
	    for(int j=m-1;j>=0;j--){
	        maxSum=max(a[i][j],maxSum);
	    }
	}
	cout<<maxSum<<endl;
	return 0;
}
