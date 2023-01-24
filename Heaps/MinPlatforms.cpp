bool compare(vector<int> a,vector<int> b){
	return a[0]<b[0];
}
int minPlatforms(int arr[],int dep[],int n){
	vector<vector<int>> combined(n);
	for(int i=0;i<n;i++){
		combined[i]={arr[i],dep[i]};
	}
	sort(combined.begin(),combined.end(),compare);
	int ans=1;
	priority_queue<int,,vector<int>,greater<int>> pq;
	pq.push(combined[0][1]);
	for(int i=1;i<n;i++){
		if(pq.top()<=combined[i][0]){
			ans++;
		}
		else{
			pq.pop();
		}
		pq.push(combined[i][1]);
	}
	return ans;
}
