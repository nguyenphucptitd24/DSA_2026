#include<bits/stdc++.h>
using namespace std;
bool dp[5005][5005];
int main (){
	string s;
	if(!(cin >> s)) return 0;
	int n = s.length();
	for(int i = 0; i < n; i++){
		dp[i][i] = true;
	}
	for(int len = 2; len <= n; len++){
		for(int i = 0; i <= n - len; i++){
			int j = i + len - 1;
			if(len == 2){
				dp[i][j] = (s[i] == s[j]);
			}
			else{
				dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
			}
		}
	}
	int m;
	cin >> m;
	while(m--){
		int l, r;
		cin >> l >> r;
		if(dp[l - 1][r - 1]){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}