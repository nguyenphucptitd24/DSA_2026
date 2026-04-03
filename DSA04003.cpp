#include<bits/stdc++.h>
using namespace std;
const long long MOD = 123456789;
long long poww(long long n, long long k){
	if(k == 0) return 1;
	if(k == 1) return n % MOD;
	long long x = poww(n, k/2);
	long long y = (x * x) % MOD;
	if(k % 2 == 0 ) return y;
	return (y * n) % MOD;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		cout << poww(2, n - 1) << endl;
	}
	return 0;
}