#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long p;
	cin >> p;
	if(p == 1){
		cout << 1 << endl;
		return;
	}
	vector<int> res;
	for(int i = 9; i >= 2; i--){
		while(p % i == 0){
			res.push_back(i);
			p /= i;
		}
	}
	if(p > 1){
		cout << -1 << endl;
	}
	else{
		sort(res.begin(), res.end());
		for(int x : res){
			cout << x;
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