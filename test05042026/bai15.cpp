#include<bits/stdc++.h>
using namespace std;
int main (){
	int n, q;
	cin >> n >> q;
	vector<int> h(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}
	vector<int> nge(n + 1, 0);
	stack<int> st;
	for(int i = n; i >= 1; i--){
		while(!st.empty() && h[st.top()] <= h[i]){
			st.pop();
		}
		if(!st.empty()){
			nge[i] = st.top();
		}
		st.push(i);
	}
	vector<int> dp(n + 1, 0);
	for(int i = n; i >= 1; i--){
		if(nge[i] != 0){
			dp[i] = 1 + dp[nge[i]];
		}
		else{
			dp[i] = 0;
		}
	}
	while(q--){
		int x;
		cin >> x;
		if(x >= 1 && x <= n){
			cout << dp[x] << endl;
		}
	}
	return 0;
}