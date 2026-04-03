#include<bits/stdc++.h>
using namespace std;
int n;
bool check = false;
int half;
vector<int> res;
void backtrack(int pos, int current_sum){
	if(current_sum == half){
		check = true;
		return;
	}
	if(current_sum > half){
		return;
	}
	for(int i = pos; i < n; i++){
		backtrack(i + 1, current_sum + res[i]);
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int sum = 0;
		res.resize(n);
		for(int i = 0; i < n; i++){
			cin >> res[i];
			sum += res[i];
		}
		half = sum / 2;
		sort(res.begin(), res.end());
		backtrack(0, 0);
		if(check) cout << "YES\n";
		else cout << "NO\n";
		check = false;
	}
}