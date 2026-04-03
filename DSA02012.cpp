#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[15][15];
int backtrack(int i, int j){
	if(i >= n || j >= m){
		return 0;
	}
	if(i == n - 1 && j == m - 1){
		return 1;
	}
	return backtrack(i, j + 1) + backtrack(i + 1, j);
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		cout << backtrack(0,0) << endl;
	}
	return 0;
}