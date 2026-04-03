#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[15][15];
bool check[15] = {true};
vector<vector<int>> res;
int cnt = 0;
void backtrack(int row, int cur, vector<int> &tmp){
	if(row == n){
		if(cur == k){
			res.push_back(tmp);
			cnt++;
		}
		return;
	}
	for(int j = 0; j < n; j++){
		if(check[j]){
			check[j] =  false;
			tmp.push_back(j + 1);
			backtrack(row + 1, cur + a[row][j], tmp);
			tmp.pop_back();
			check[j] = true;
		}
	}
}
int main (){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < 15; i++){
		check[i] = true;
	}
	vector<int> tmp;
	backtrack(0,0,tmp);
	cout << cnt << endl;
	for(int i = 0; i < res.size(); i++){
		for (int j = 0; j < n; j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}