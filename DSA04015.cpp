#include<bits/stdc++.h>
using namespace std;
void solve (){
	int n;
	long long k;
	cin >> n >> k;
	long long a[n];
	for(int i =0 ; i < n; i++){
		cin >> a[i];
	}
	if(k < a[0]){
		cout << -1 << endl;
		return;
	}
	if(k > a[n - 1]){
		cout << a[n - 1] << endl;
		return;
	}
	for(int i = 1; i < n; i++){
		if(a[i] > k){
			cout << i << endl;
			return;
		}
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