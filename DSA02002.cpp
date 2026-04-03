#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void backtrack(vector<int> a){
	res.push_back(a);
	int n = a.size();
	if(a.size() == 1) return;
	vector<int> b;
	for(int i = 0; i < n - 1; i++){
		b.push_back(a[i] + a[i + 1]);
	}
	backtrack(b);
}
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		res.clear();
		backtrack(a);
		for(int i = res.size() - 1; i >= 0; i--){
			cout << "[";
			for(int j = 0; j < res[i].size(); j++){
				cout << res[i][j];
				if(j != res[i].size() - 1) cout << " ";
			}
			cout << "] ";
		}
		cout << endl;
	}
	return 0;
}