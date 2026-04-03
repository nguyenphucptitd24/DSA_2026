#include<bits/stdc++.h>
using namespace std;
long long n;
const long long MOD = 1e9 + 7;
struct Matrix{
	long long mat[2][2];
	Matrix(){
		mat[0][0] = mat[0][1] = mat[1][1] = mat[1][0] = 0;
	}
};
Matrix multiply(Matrix a, Matrix b){
	Matrix C;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
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
	cin >> n;
	Matrix a;
	a.mat[0][0] = a.mat[1][0] = a.mat[0][1] = 1;
	a.mat[1][1] = 0;
	Matrix res = poww(a, n);
	cout << res.mat[0][1] << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}