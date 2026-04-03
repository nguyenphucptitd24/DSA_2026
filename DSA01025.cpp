#include<bits/stdc++.h>
using namespace std;
int n, k;
int res[20];
void backtrack(int pos){
	if(pos > k){
		for(int i = 1; i <= k; i++){
			cout << (char)(res[i] + 'A' - 1);
		}
		cout << endl;
		return;
	}
	for(int i = res[pos - 1] + 1; i <= n + pos - k; i++){
		res[pos] = i;
		backtrack(pos + 1);
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		res[0] = 0;
		backtrack(1);
	}
	return 0;
}