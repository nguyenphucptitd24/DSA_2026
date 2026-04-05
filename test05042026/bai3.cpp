#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	getline(cin >> ws, s);
	int n = s.length();
	vector<string> res(n);
	stack<int> st;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			st.push(i);
		}
		else if(s[i] == ')'){
			if(!st.empty()){
				res[st.top()] = "0";
				res[i] = "1";
				st.pop();
			}
			else{
				res[i] = "-1";
			}
		}
	}
	while(!st.empty()){
		res[st.top()] = "-1";
		st.pop();
	}
	for(int i = 0; i < n; i++){
		if(s[i] != '(' && s[i] != ')'){
			cout << s[i];
		}
		else{
			cout << res[i];
		}
	}
	cout << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}