#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int tong_truoc = 0, tong_sau = 0;
		k = min(k, n - k);
		for(int i = 0; i < n; i++){
			if(i < k){
				tong_truoc += a[i];
			}
			else{
				tong_sau += a[i];
			}
		}
		cout << abs(tong_truoc - tong_sau) << endl;
	}
	return 0;
}