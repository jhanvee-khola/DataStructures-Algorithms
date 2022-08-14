#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void dfs(vector<int> adj[],vector<bool> &visit,int node){
        visit[node]=true;
        for(auto it:adj[node]){
            if(!visit[it]){
                dfs(adj,visit,it);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[]){
	    for(int i=0;i<V;i++){
	        vector<bool> visit(V,false);
	        dfs(adj,visit,i);
	        bool flag=true;
	        for(int j=0;j<V;j++){
	            if(!visit[j]){
	                flag=false;
	                break;
	            }
	        }
	        if(flag){
	            return i;
	        }
	    }
	    return -1;
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
