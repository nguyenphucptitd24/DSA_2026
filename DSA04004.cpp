#include<bits/stdc++.h>
using namespace std;
void solve (){
	long long n, k;
	cin >> n >> k;
	long long center = 1LL << (n - 1);
	while(true){
		if (n == 1) {
			cout << "1\n";
			break;
		}
		if (center == k) {
			cout << n << endl;
			break;
		}
		else{
			if(k > center){
				k = k - center;
			}
			n--;
			center /= 2;
		} 
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}