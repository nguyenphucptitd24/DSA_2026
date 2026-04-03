#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
int n, k;
vector<int> a;
void backtrack(int tong, int start_idx, vector<int> &curr){
	if(tong == k){
		res.push_back(curr);
		return;
	}
	for(int i = start_idx; i < n; i++){
		if(tong + a[i] <= k){
			curr.push_back(a[i]);
			backtrack(tong + a[i], i, curr);
			curr.pop_back();
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
		res.clear();
		a.resize(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> tmp;
		sort(a.begin(), a.end());
		backtrack(0,0,tmp);
		if(res.empty()){
			cout << -1 << endl;
		}
		else{
			for(int i = 0; i < res.size(); i++){
				cout << '[';
				for(int j = 0; j < res[i].size(); j++){
					cout << res[i][j];
					if(j != res[i].size() - 1){
						cout << " ";
					}
				}
				cout << "]";
			}
		}
		cout << endl;
	}
	return 0;
}