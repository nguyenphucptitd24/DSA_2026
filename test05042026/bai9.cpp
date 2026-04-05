#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
struct Matrix {
	int n;
	vector<vector<ll>> mat;
	Matrix(int size) : n(size), mat(size, vector<ll>(size, 0)) {
	}
};
Matrix multiply(Matrix a, Matrix b){
	Matrix res(a.n);
	for(int i = 0; i < a.n; i++){
		for(int k = 0; k < a.n; k++){
			if(a.mat[i][k] == 0){
				continue;
			}
			for(int j = 0; j < a.n; j++){
				res.mat[i][j] = (res.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
			}
		}
	}
	return res;
}
Matrix power(Matrix a, ll k){
	Matrix res(a.n);
	for(int i = 0; i < a.n; i++){
		res.mat[i][i] = 1;
	}
	while(k > 0){
		if(k & 1) res= multiply(res, a);
		a = multiply(a, a);
		k >>= 1;
	}
	return res;
}
void solve(){
	int n;
	ll k;
	cin >> n >> k;
	Matrix a(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a.mat[i][j];
		}
	}
	Matrix res = power(a, k);
	ll sum_last_row = 0;
	for(int j = 0; j< n; j++){
		sum_last_row = (sum_last_row + res.mat[n - 1][j]) % MOD;
	}
	cout << sum_last_row << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}