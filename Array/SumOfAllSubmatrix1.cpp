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
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        for(int k=i;k<n;k++){
	            for(int l=j;l<m;l++){
	                for(int m=i;m<=k;m++){
	                    for(int n=j;n<=l;n++){
	                        ans+=a[m][n];
	                    }
	                }
	            }
	        }
	    }
	}
	return 0;
}
