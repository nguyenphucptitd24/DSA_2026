#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int dp[2][2005][2][2];
int main(){
	int m, d;
	while(cin >> m >> d){
		string a, b;
		cin >> a >> b;
		int n = a.size();
		memset(dp, 0, sizeof(dp));
		dp[0][0][1][1] = 1;
		for(int i = 0; i < n; i++){
			int cur = i % 2;
			int next = (i + 1) % 2;
			memset(dp[next], 0, sizeof(dp[next]));
			bool even_pos = ((n - i) % 2 == 0);
			for(int rem = 0; rem < m; rem++){
				for(int lt = 0; lt < 2; lt++){
					for(int ht = 0; ht < 2; ht++){
						if(dp[cur][rem][lt][ht] == 0) continue;
						int lower = lt ? (a[i] - '0') : 0;
						int upper = ht ? (b[i] - '0') : 9;
						for(int digit = lower; digit <= upper; digit++){
							if(even_pos){
								if(digit != d){
									continue;
								}
							}
							else{
								if(digit == d) continue;
							}
							int next_rem =  (rem * 10 + digit) % m;
							int next_lt = lt && (digit == lower);
							int next_ht = ht && (digit == upper);
							dp[next][next_rem][next_lt][next_ht] = (dp[next][next_rem][next_lt][next_ht] + dp[cur][rem][lt][ht]) % MOD;
						}
					}
				}
			}
		}
		long long ans = 0;
		for(int lt = 0; lt < 2; lt++){
			for(int ht = 0; ht < 2; ht++){
				ans = (ans + dp[n % 2][0][lt][ht]) % MOD;
			}
		}
		cout << ans << endl;
	}
	return 0;
}