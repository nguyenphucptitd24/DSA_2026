#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isOp(string s){
	return (s == "+" || s == "-" || s == "*" || s == "/");
}
ll calc(ll a, ll b, string op){
	if(op == "+") return a + b;
	if(op == "-") return a - b;
	if(op == "*") return a * b;
	if(op == "/") return a / b;
	return 0;
}
void solve(){
	int n;
	cin >> n;
	vector<string> tokens(n);
	for(int i = 0; i < n; i++){
		cin >> tokens[i];
	}
	stack<ll> st;
	if(isOp(tokens[0]) && tokens[0].size() == 1){
		for(int i = n - 1; i >= 0; i--){
			if(isOp(tokens[i]) && tokens[i].size() == 1){
				ll o1 = st.top();
				st.pop();
				ll o2 = st.top();
				st.pop();
				st.push(calc(o1, o2, tokens[i]));
			}
			else{
				st.push(stoll(tokens[i]));
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(isOp(tokens[i]) && tokens[i].size() == 1){
				ll o2 = st.top();
				st.pop();
				ll o1 = st.top();
				st.pop();
				st.push(calc(o1, o2, tokens[i]));
			}
			else{
				st.push(stoll(tokens[i]));
			}
		}
	}
	cout << st.top() << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}