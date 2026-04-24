#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a(20);
void backtrack(int pos, vector<int> &curr){
	if(pos == k){
		for(int i = 0; i < k; i++){
			cout << curr[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i = pos; i < n; i++){
		curr.push_back(a[i]);
		backtrack(pos + 1, curr);
		curr.pop_back();
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<int> curr;
		backtrack(0, curr);
	}
	return 0;
}