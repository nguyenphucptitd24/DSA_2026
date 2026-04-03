#include<bits/stdc++.h>
using namespace std;
void solve (){
	int n;
	cin >> n;
	vector<long long> a(n);
	long long max_val = -2e18;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > max_val){
			max_val = a[i];
		}
	}
	int max_len = 0;
	int current_len = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == max_val){
			current_len++;
			if(current_len > max_len){
				max_len = current_len;
			}
			else{
				current_len = 0;
			}
		}
	}
	cout << max_len << endl;
}
int main  (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n_val;
	while(cin >> n_val){
		vector<long long> a(n_val);
		long long mv = -2e18;
		for(int i = 0; i < n_val; i++){
			cin >> a[i];
			if(a[i] > mv) mv = a[i];
		}
		int ml = 0, cl = 0;
		for(int i = 0; i < n_val; i++){
			if(a[i] == mv){
				cl++;
				if(cl > ml) ml = cl;
			}
			else{
				cl = 0;
			}
		}
		cout << ml << endl;
	}
	return 0;
}