#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		set<int> v;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			v.insert(a[i]);
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
			v.insert(b[i]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int x : v){
			cout << x << " ";
		}
		cout << endl;
		int i = 0, j = 0;
		while(i < n && j < m){
			if(a[i] < b[j]){
				i++;
			}
			else if (a[i] > b[j]){
				j++;
			}
			else{
				cout << a[i++] << " ";
				j++;
			}
		}
		cout << endl;
	}
	return 0;
}