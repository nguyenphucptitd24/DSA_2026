#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, k;
struct Matrix{
	long long mat[11][11];
	Matrix(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				mat[i][j] = 0;
			}
		}
	}
};
Matrix multiply(Matrix a, Matrix b){
	Matrix C;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				C.mat[i][j] = (C.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD; 
			}
		}
	}
	return C;
}
Matrix poww(Matrix a, long long n){
	if(n == 1) return a;
	Matrix tmp = poww(a, n/2);
	Matrix X = multiply(tmp, tmp);
	if(n % 2 == 0) return X;
	return multiply(X, a);
}
void solve(){
	cin >> n >> k;
	Matrix A;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> A.mat[i][j];
		}
	}
	Matrix res = poww(A, k);
	long long current_sum = 0;
	for(int i = 0; i < n; i++){
		current_sum = (current_sum + res.mat[i][n - 1]) % MOD;
	}
	cout << current_sum << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}