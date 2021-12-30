#include <bits/stdc++.h>
using namespace std;

int main() {
	//Brute Force -> O(n^6) time
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
	//-----------------------------------------------------------------
	
	//Optimised Approach -> O(n^4) time
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
	        if(i!=0){
		    b[i][j]+=b[i-1][j];
		}
	    }
	}
	//can also be done in O(1) space by modifying the matrix 'a' in-place instead of using matrix 'b'
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
	//-------------------------------------------------------------------------
	
	//Optimal Solution -> O(n^2) time
	int ans=0;
	//adding the contributing factor of each element of the matrix in the final sum of all sub-matrices by finding its no. of occurences
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        ans+=a[i][j]*((i+1)(j+1)(n-i)(m-i));
	    }
	}
	return 0;
}
