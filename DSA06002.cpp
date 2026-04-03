#include<bits/stdc++.h>
using namespace std;
int k;
bool cmp(int x, int y){
	return abs(k - x) < abs(k - y);
}
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end(), cmp);
		for(int i = 0; i < n; i++){
			cout <<  a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}