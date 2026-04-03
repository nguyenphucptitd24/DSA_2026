#include<bits/stdc++.h>
using namespace std;
void solve (){
	string s;
	cin >> s;
	stack<int> st;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			st.push(s[i] - '0');
		}
		else{
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			int res;
			if(s[i] == '+'){
				res = num1 + num2;
			}
			else if (s[i] == '-'){
				res = num2 - num1;
			}
			else if (s[i] == '*'){
				res = num1 * num2;
			}
			else{
				res = num2 / num1;
			}
			st.push(res);
		}
	}
	int res = st.top();
	cout << res << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}