#include<bits/stdc++.h>
using namespace std;
int n, k;
int X[200];
int cnt = 1;
bool isPrime(int n){
	if(n < 2) return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return 0;
	}
	return 1;
}
void Try(int pos){
	if(pos > k){
		if(isPrime(cnt)){
			cout << cnt << ": ";
			for(int i = 1; i <= k; i++){
			cout << X[i] << " ";
			}
			cout << endl;
		}
		cnt++;
		return;
	}
	for(int i = X[pos - 1] + 1; i <= n - k + pos; i++){
		X[pos] = i;
		Try(pos + 1);
	}
}
int main (){
	cin >> n >> k;
	Try(1);
	return 0;
}