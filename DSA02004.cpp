#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int n;
vector<char> res;
bool visited[10][10] = {false};
bool found = false;
void Try(int i, int j){
	if(i == n - 1 && j == n - 1){
		found = true;
		for(int k = 0; k < res.size(); k++){
			cout << res[k];
		}
		cout << " ";
		return;
	}
	visited[i][j] = true;
	if(i + 1 < n && a[i + 1][j] == 1 && visited[i+1][j] == false){
		res.push_back('D');
		Try(i + 1, j);
		res.pop_back();
	}
	if(j - 1 >= 0 && a[i][j - 1] == 1 && visited[i][j-1] == false){
		res.push_back('L');
		Try(i, j - 1);
		res.pop_back();
	}
	if(j + 1 < n && a[i][j + 1] == 1 && visited[i][j+1] == false){
		res.push_back('R');
		Try(i, j + 1);
		res.pop_back();
	}
	if(i - 1 >= 0 && a[i - 1][j] == 1 && visited[i-1][j] == false){
		res.push_back('U');
		Try(i - 1, j);
		res.pop_back();
	}

	visited[i][j] = false;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		memset(visited,false, sizeof(visited));
		found = false;
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		Try(0,0);
		if(found == false) cout << -1 << endl;
		cout << endl;
	}
	return 0;
}