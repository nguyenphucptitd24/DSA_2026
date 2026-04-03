#include<bits/stdc++.h>
using namespace std;
int main (){
	int n, q;
	cin >> n >> q;
	vector<int> d(n + 2, 0);
	while(q--){
		int x, y;
		cin >> x >> y;
		d[x]++;
		d[y + 1]--;
	}
	int current_flips = 0;
	for(int i = 1; i <= n; i++){
		current_flips += d[i];
		cout << (current_flips % 2) << (i == n ? "" : " ");
	}
	cout << endl;
	return 0;
}