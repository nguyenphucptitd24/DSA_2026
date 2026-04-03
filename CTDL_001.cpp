#include<bits/stdc++.h>
using namespace std;
int n, X[200];
bool final = false;
void khoitao(){
	for(int i = 1; i <= n; i++){
		X[i] = 0;
	}
}
void sinh(){
	int i = n;
	while(i > 0 && X[i] == 1){
		X[i] = 0;
		i--;
	}
	if(i == 0) final = true;
	else{
		X[i] = 1;
	}
}
bool check(int a[], int n){
	for(int i = 1; i <= (n/2); i++){
		if(a[i] != a[n - i + 1]){
			return 0;
		}
	}
	return 1;
}
int main (){
	cin >> n;
	khoitao();
	while(!final){
		if(check(X, n)){
			for(int i = 1; i <= n; i++){
				cout << X[i] << " ";
			}
			cout << endl;
		}
		sinh();
	}
	return 0;
}