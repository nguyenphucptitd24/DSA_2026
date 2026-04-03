#include<bits/stdc++.h>
using namespace std;
int prime[201];
int n, p, s;
vector<int> primes_list;
vector<vector<int>> res;
void sieves(){
	fill(prime, prime + 201, 1);
	prime[0] = prime[1] = 0;
	for(int i = 2; i * i < 201; i++){
		if(prime[i] == 1){
			for(int j = i * i; j < 201; j += i){
				prime[j] = 0;
			}
		}
	}
}
void backtrack(int curr, int count, int start_idx, vector<int> &tmp){
	if(curr == s && count == n){
		res.push_back(tmp);
		return;
	}
	if(curr > s || count > n || start_idx == primes_list.size()){
		return;
	}
	for(int i = start_idx; i < primes_list.size(); i++){
		if(curr + primes_list[i] <= s){
			tmp.push_back(primes_list[i]);
			backtrack(curr + primes_list[i], count + 1, i + 1, tmp);
			tmp.pop_back();
		}
		else{
			break;
		}
	}
}
void solve(){
	cin >> n >> p >> s;
	primes_list.clear();
	res.clear();
	for(int i = p + 1; i < s; i++){
		if(prime[i] == 1){
			primes_list.push_back(i);
		}
	}
	vector<int> tmp;
	backtrack(0,0,0,tmp);
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < n; j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
int main (){
	int t;
	cin >> t;
	sieves();
	while(t--){
		solve();
	}
	return 0;
}