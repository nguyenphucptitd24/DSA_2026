#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] == k) cnt++;
		}
		if(cnt == 0) cout << -1 << endl;
		else cout << cnt << endl;
	}
	return 0;
}