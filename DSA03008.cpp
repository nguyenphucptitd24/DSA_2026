#include<bits/stdc++.h>
using namespace std;
struct SapXep{
	int start, finish;
};
bool cmp (SapXep a, SapXep b){
	return a.finish < b.finish;
}
void solve(){
	int n;
	cin >> n;
	vector<int> s(n), f(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++) cin >> f[i];
	vector<SapXep> a(n);
	for(int i = 0; i < n; i++){
		a[i].start = (s[i]);
		a[i].finish = (f[i]);
	}
	sort(a.begin(), a.end(), cmp);
	int i = 1;
	int flag = 0;
	int cnt = 1;
	while(i < n){
		if(a[i].start >= a[flag].finish){
			flag = i;
			cnt++;
		}
		i++;
	}
	cout << cnt << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}