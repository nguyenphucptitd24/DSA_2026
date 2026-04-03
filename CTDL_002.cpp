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
    else {
        X[i] = 1;
    }
}
int main (){
	int k;
	cin >> n >> k;
	int cnt = 0;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	khoitao();
	while(!final){
		int tong = 0;
		int j = 1;
		for(int i = 1; i <= n; i++){
			if(X[i] == 1) tong += a[i];
		}
		if (tong == k){
			cnt++;
			for(int x = 1; x <= n; x++){
				if(X[x] == 1) cout << a[x] << " ";
			}
			cout << endl;
		}
		sinh();
	}
	cout << cnt;
	return 0;
}