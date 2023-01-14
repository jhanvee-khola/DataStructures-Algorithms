//A group of two or more people wants to meet and minimize the total travel distance. 
//You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
//The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

int minDist(vector<vector<int>> grid){
    vector<int> rows;
	vector<int> cols;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                rows.push_back(i);
				cols.push_back(j);
            }
        }
    }
	sort(rows.begin(),rows.end());
	sort(cols.begin(),cols.end());
	int n=rows.size(),mid=n/2;
	int x=rows[n/2];
	int y=colss[n/2];
	int dist=0;
	for(int i=0;i<n;i++){
		dist+=abs(rows[i]-x)+abs(cols[i]-y);
	}
	return dist;
}
