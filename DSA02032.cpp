#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
vector<vector<int>> res;
void backtrack(int curr, int start_idx, vector<int> &tmp){
	if(curr == k){
		res.push_back(tmp);
		return;
	}
	for(int i = start_idx; i < n; i++){
		if(curr + a[i] <= k){
			tmp.push_back(a[i]);
			backtrack(curr + a[i], i, tmp);
			tmp.pop_back();
		}
		else{
			break;
		}
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		a.resize(n);
		res.clear();
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<int> tmp;
		backtrack(0,0,tmp);
		if(res.empty()){
			cout << -1 << endl;
		}
		else{
			cout << res.size() << " ";
			for(int i = 0; i < res.size(); i++){
				cout << '{';
				for(int j = 0; j < res[i].size(); j++){
					cout << res[i][j];
					if(j != res[i].size() - 1){
						cout << " ";
					}
				}
				cout << "} ";
			}
			cout << endl;
		}
	}
	return 0;
}