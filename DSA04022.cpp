#include<bits/stdc++.h>
using namespace std;
char findChar(int n, int k){
	if(n == 1) return 'A';
	long long m = 1LL << (n - 1);
	if(m == k) return ('A' + n - 1);
	if(k < m) return findChar(n - 1, k);
	if(k > m) return findChar(n - 1, k - m);
}
int main (){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << findChar(n, k) << endl;
	}
	return 0;
}