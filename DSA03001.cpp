#include<bits/stdc++.h>
using namespace std;
int a[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int dem(int n){
	int dem = 0;
	for(int i = 0; i < 10; i++){
		int count = n / a[i];
		dem += count;
		n = n % a[i];
	}
	return dem;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << dem(n) << endl;
	}
}