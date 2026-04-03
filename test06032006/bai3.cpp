#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF =  2e18;
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	vector<ll> prev_dp(3);
	prev_dp[0] = 0;
	prev_dp[1]= b[0];
	prev_dp[2] = 2 * b[0];
	for(int i = 1; i < n; i++){
		vector<ll> curr_dp(3, INF);
		for(int j  =0; j < 3; j++){
			ll val_i = a[i] + j;
			for(int k = 0; k < 3; k++){
				ll val_prev = a[i - 1] + k;
				if(val_i != val_prev){
					curr_dp[j] = min(curr_dp[j], prev_dp[k] + (ll)j * b[i]);
				}
			}
 		}
 		prev_dp = curr_dp;
	}
	cout << min({prev_dp[0], prev_dp[1], prev_dp[2]}) << "\n";
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}