#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long poww(long long n, long long k){
	if (k == 0) return 1;
	long long x = poww(n, k /2);
	long long y = (x * x) % MOD;
	if(k % 2 == 0) return y;
	return (n * y) % MOD;
}
long long reverse(long long n){
	long long res = 0;
	while(n > 0){
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long r = reverse(n);
		cout << poww(n, r) << endl;
	}
	return 0;
}