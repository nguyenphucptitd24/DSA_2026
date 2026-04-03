#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		int dem = 0;
		int a[n], b[m];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		int i = 0, j = 0;
		while(i < n && j < m){
			if(a[i] < b[j]){
				i++;
				dem++;
				if(dem == k){
					cout << a[i - 1] << endl;
					break;
				}
			}
			else{
				j++;
				dem++;
				if(dem == k){
					cout << b[j - 1] << endl;
					break;
				}
			}
		}
	}
	return 0;
}