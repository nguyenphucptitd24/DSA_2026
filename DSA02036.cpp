#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<vector<int>> res;
void backtrack(int index, vector<int> &current){
	if(index == n){
		if(!current.empty()){
			int sum = accumulate(current.begin(), current.end(), 0);
			if(sum % 2 != 0) res.push_back(current);
		}
		return;
	}
	backtrack(index + 1, current);
	current.push_back(a[index]);
	backtrack(index + 1, current);
	current.pop_back();
}
void solve(){
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	res.clear();
	vector<int> current;
	backtrack(0, current);
	sort(current.begin(), current.end());
	for(const auto& result : res){
		for(int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}