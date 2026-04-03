#include<bits/stdc++.h>
using namespace std;
int a[501][501];
int n, m;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void DFS(int x, int y){
	a[x][y] = 0;
	for(int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < n && nx >= 0 && ny < m && ny >= 0 && a[nx][ny] == 1){
			DFS(nx, ny);
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 1){
				cnt++;
				DFS(i, j);
			}
		}
	}
	cout << cnt << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}