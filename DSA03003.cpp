#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long tong = 0;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for(int i = 0; i < n; i++){
			long long tmp = a[i] * i;
			tmp %= MOD;
			tong = (tong + tmp) % MOD;
		}
		cout << tong << endl;
	}
}