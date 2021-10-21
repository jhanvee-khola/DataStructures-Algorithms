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
	
	int ans=0;
	//adding the contributing factor of each element of the matrix in the final sum of all sub-matrices by finding its no. of occurences
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        ans+=a[i][j]*((i+1)(j+1)(n-i)(m-i));
	    }
	}
	
	return 0;
}
