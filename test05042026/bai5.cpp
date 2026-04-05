#include<bits/stdc++.h>
using namespace std;
vector<string> res;
void init(){
	queue<string> q;
	q.push("6");
	q.push("8");
	while(res.size() < 10000){
		string s = q.front();
		q.pop();
		string tmp = s;
		reverse(tmp.begin(), tmp.end());
		res.push_back(s + tmp);
		q.push(s + "6");
		q.push(s + "8");
	}
}
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << res[i] <<" ";
	}
	cout << endl;
}
int main (){
	init();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}