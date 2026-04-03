#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> b = a;
		sort(b.begin(), b.end());
		bool check = true;
		for(int i = 0; i < n; i++){
			if(a[i] != b[i] && a[i] != b[n - i - 1]){
				check = false;
				cout << "No\n";
				break;
			}
		}
		if(check == true) cout << "Yes\n";
	}
	return 0;
}