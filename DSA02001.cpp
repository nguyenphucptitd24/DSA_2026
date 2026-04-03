#include<bits/stdc++.h>
using namespace std;
void backtrack(vector<int> a){
	int n = a.size();
	if(n == 0) return;
	cout << "[";
	for(int i = 0; i < n; i++){
		cout << a[i];
		if(i != n - 1) cout << " ";
	}
	cout << "]" << endl;
	if (n == 1) return;
	vector<int> b;
	for(int i = 0; i < n - 1; i++){
		b.push_back(a[i] + a[i + 1]);
	}
	backtrack(b);
}
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
		backtrack(a);
	}
	return 0;
}