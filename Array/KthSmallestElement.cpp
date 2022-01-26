#include <bits/stdc++.h>
using namespace std;

//O(nlogn) time
int kthSmallest(int arr[],int n,int k){
	sort(arr, arr + n);
	return arr[k - 1];
}

//O(n) time
int main(){
  int n,k;
  cin>>n>>k;
	int arr[n];
	set<int> s(arr,arr+n);
	set<int>::iterator itr=s.begin();
	advance(itr, k - 1);
	cout<<*itr;
	return 0;
}
