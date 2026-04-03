#include<bits/stdc++.h>
using namespace std;
int n, X[200];
bool final = false;
void khoitao(){
	for(int i = 1; i <= n; i++){
		X[i] = i;
	}
}
void sinh(){
	int i = n;
	while(i > 0 && X[i] > X[i + 1]){
		i--;
	}
	if(i == 0) final = true;
	else{
		int j = n;
		while(X[i] > X[j]) j--;
		swap(X[i], X[j]);
		reverse(X + i + 1, X + n + 1);
	}
}
int main (){
	cin >> n;
	khoitao();
	int cnt = 1;
	while(!final){
		cout << cnt << ": ";
		for(int i = 1; i <= n; i++){
			cout << X[i] << " ";
		}
		cout << endl;
		sinh();
		cnt++;
	}
	return 0;
}