#include<bits/stdc++.h>
using namespace std;
using namespace std;
const int MAX = 100005;
int lpf[MAX];
long long prefix_sum[MAX];
void sieve(){
	for(int i = 2; i < MAX; i++){
		if(lpf[i] == 0){
			for(int j = i; j < MAX; j+=i){
				lpf[j] = i;
			}
		}
	}
	prefix_sum[0] = prefix_sum[1] = 0;
	for(int i = 2; i < MAX; i++){
		prefix_sum[i] = prefix_sum[i - 1] + lpf[i];
	}
}
void solve(){
	int l , r;
	cin >> l >> r;
	cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
}
int main (){
	sieve();
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}