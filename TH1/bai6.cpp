#include<bits/stdc++.h>
using namespace std;
void solve(){
	double a, b ,c;
	cin >> a >> b >> c;
	double low = 0, high = 1000;
	for(int i = 0; i < 100; i++){
		double mid = (low + high) / 2.0;
		if(a * mid * mid * mid + b * mid > c){
			high = mid;
		}
		else{
			low = mid;
		}
	}
	cout << fixed << setprecision(4) << low << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}