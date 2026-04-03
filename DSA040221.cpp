#include<bits/stdc++.h>
using namespace std;
long long f[93];
void fibo(){
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i < 93; i++){
		f[i] = f[i - 2] + f[i - 1];
	}
}
char findChar(int n, long long k){
	if(n == 1) return '0';
	if(n == 2) return '1';
	if(k <= f[n - 2]){
		return findChar(n - 2, k);
	}
	else{
		return findChar(n - 1, k - f[n - 2]);
	}
}
int main (){
	int t;
	cin >> t;
	fibo();
	while(t--){
		int n;
		long long k;
		cin >> n >> k;
		cout << findChar(n , k) << endl;
	}
	return 0;
}