#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int key;
	cin>>key;
	for(int i=0;i<n;i++){
		int k=key-a[i],j=i+1,l=n-1;
		while(j<l){
			if(a[j]+a[l]==k){
				cout<<a[i]<<", "<<a[j]<<" and "<<a[l]<<endl;
				j++;
				l--;
			}
			else if(a[j]+a[l]<k){
				j++;
			}
			else{
				l--;
			}
		}

	}
	return 0;
}
