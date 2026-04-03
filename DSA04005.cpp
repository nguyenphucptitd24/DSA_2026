#include<bits/stdc++.h>
using namespace std;
long long f[100];
int n;
void fibo(){
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i < 93; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
}
char findChar(long long n, long long i){
	while(n > 2){
		if(i <= f[n - 2]){
			n = n - 2;
		}
		else{
			i = i - f[n - 2];
			n--;
		}
	}
	if (n == 1) return 'A';
	return 'B';
}
void solve(){
	long long k;
	cin >> n >> k;
	fibo();
	cout << findChar(n, k) << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}