#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long poww(long long a, long long b){
	if(b == 1) return a;
	if(b == 0) return 1;
	long long x = poww(a, b/ 2);
	long long y = (x * x) % MOD;
	if(b % 2 == 0) return y;
	return (a * y) % MOD;
}

int main (){
	long long a;
	long long b;
	while (cin >> a >> b){
		if(a == 0 && b == 0) break;
		else{
			cout << poww(a, b) << endl;
		}
	}
}