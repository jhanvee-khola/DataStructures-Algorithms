#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,d;
	cin>>n>>d;
	long long a[n];
	for(long long i=0;i<n;i++){
	    cin>>a[i];
	}
	sort(a,a+n);
	int ans=0,i=0;
	while(i<n-1){
	    if(a[i+1]-a[i]<=d){
	        ans++;
	        i+=2;
	    }
	    else{
	        i++;
	    }
	}
	cout<<ans;
	return 0;
}
