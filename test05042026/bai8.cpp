#include<bits/stdc++.h>
using namespace std;
void bfs(int s, int n, const vector<vector<int>>& adj){
	vector<int> parent(n + 1, 0);
	vector<bool> visited(n + 1, false);
	queue <int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				visited[v] = true;
				parent[v] = u;
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(i == s) continue;
		if(!visited[i]){
			cout << "No path\n";
		}
		else{
			vector<int> path;
			for(int v = i; v != 0; v = parent[v]) path.push_back(v);
			reverse(path.begin(), path.end());
			for(int j = 0; j < path.size(); j++){
				cout << path[j] << (j == path.size() - 1 ? "" : " ");
			}
			cout << "\n";
		}
	}
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m, s;
		cin >> n >> m >> s;
		vector<vector<int>> adj(n + 1);
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i = 1; i <= n; i++){
			sort(adj[i].begin(), adj[i].end());
		}
		bfs(s, n, adj);
	}
	return 0;
}