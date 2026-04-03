#include<bits/stdc++.h>
using namespace std;
int main (){
	int n, q;
	cin >> n >> q;
	vector<long long> p(n + 1, 0);
	for(int i = 1; i <= n; i++){
		long long x;
		cin >> x;
		p[i] = p[i - 1] + (x > 0 ? x : 0);
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		if(l > r) swap(l, r);
		cout << p[r] - p[l - 1] << "\n";
	}
	return 0;
}