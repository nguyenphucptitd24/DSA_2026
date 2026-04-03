#include<bits/stdc++.h>
using namespace std;
const int MOD = 100;
struct Matrix {
	long long mat[2][2];
	Matrix(){
		mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
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
	if(n == 1) return A;
	Matrix tmp = poww(A, n/2);
	Matrix res = multiply(tmp, tmp);
	if(n % 2 == 0) return res;
	return multiply(res, A);
}
void solve(){
	long long n; cin >> n;
	if (n == 0) {
        cout << "01" << endl;
        return;
    }
	Matrix X;
	X.mat[0][0] = 2, X.mat[0][1] = 3, X.mat[1][0] = 1, X.mat[1][1] = 2;
	Matrix res = poww(X, n);
	long long an = res.mat[0][0];
	long long ans = (2 * an) - 1;
	ans = (ans % MOD + MOD) % MOD;
	if (ans < 10) cout << "0" << ans << endl;
	else cout << ans << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
