#include<bits/stdc++.h>
using namespace std;
void solve(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		string s;
		cin >> s;
		string res = "";
		stack<int> st;
		for(int j = 0; j <= s.length(); j++){
		st.push(j + 1);
			if(j == s.length() || s[j] == 'I'){
				while(!st.empty()){
					res += to_string(st.top());
					st.pop();
				}
			}
		}
		cout << "Test " << i << ": " << res << endl;
	}
}
int main (){
	solve();
	return 0;
}