#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[10004];
void DFS(int u){
	cout << u << " ";
	visited[u] =  true;
	for(int v : adj[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

void solve(){
	int v, e, startNode;
	cin >> v >> e >> startNode;
	for(int i = 1; i <= v; i++){
		adj[i].clear();
		visited[i] = false;
	}
	for(int i = 0; i < e; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= v; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	DFS(startNode);
	cout << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}