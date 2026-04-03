#include<bits/stdc++.h>
using namespace std;
void solve(string s){
	vector<int> cnt(10, 0);
	for(char c : s){
		cnt[c - '0']++;
	}
	int n = s.length();
	if(n == 1){
		if((s[0] - '0') % 8 == 0) cout << "YES\n";
		else cout << "NO\n";
		return;
	}
	else if(n == 2){
		for(int i = 16; i <= 96; i+=8){
			int d1 = i/10, d2 = i % 10;
			if(d1 == 0 || d2 == 0){
				continue;
			}
			cnt[d1]--;
			cnt[d2]--;
			if(cnt[d1] >= 0 && cnt[d2] >= 0){
				cout << "YES\n";
				return;
			}
			cnt[d1]++; cnt[d2]++;
		}
		cout << "NO\n";
		return;
	}
	for(int i = 104; i <= 992; i+=8){
		int tmp = i;
		int d3 = tmp % 10;
		tmp /=10;
		int d2 = tmp % 10;
		tmp /= 10;
		int d1 = tmp;
		if(d1 == 0 || d2 == 0 || d3 == 0){
			continue;
		}
		cnt[d1]--;
		cnt[d2]--;
		cnt[d3]--;
		if(cnt[d1] >= 0 && cnt[d2] >= 0 && cnt[d3] >= 0){
			cout << "YES\n";
			return;
		}
		cnt[d1]++;
		cnt[d2]++;
		cnt[d3]++;
	}
	cout << "NO\n";
}

int main (){
	string s;
	cin >> s;
	solve(s);
	return 0;
}