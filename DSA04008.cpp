#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct Matrix{
	long long mat[2][2];
	Matrix(){
		mat[0][0] = mat[1][0] = mat[0][1] = mat[1][1] = 0;
	}
};
Matrix multiply(Matrix A, Matrix B){
	Matrix C;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
			}
		}
	}
	return C;
}
Matrix poww(Matrix A, long long n){
	if (n == 1) return A;
	Matrix X = poww(A, n / 2);
	Matrix Y = multiply(X,X);
	if(n % 2 == 0) return Y;
	return multiply(Y, A);
}
void solve(){
	int n;
	cin >> n;
	if(n == 0 || n == 1){
		cout << n << endl;
		return;
	}
	Matrix a;
	a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1;
	a.mat[1][1] = 0;
	Matrix res = poww(a, n);
	Matrix start;
	start.mat[0][0] = 1;
	start.mat[1][0] = 0;
	Matrix result;
	result = multiply(res, start);
	cout << result.mat[1][0] << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
