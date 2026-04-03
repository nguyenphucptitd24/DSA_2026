#include<bits/stdc++.h>
using namespace std;
int priority(char op){
	if(op == '+' || op == '-'){
		return 1;
	}
	else if(op == '*' || op == '/'){
		return 2;
	}
	return 0;
}

long long compute(long long a, long long b, char op){
	switch(op){
		case '+' : return a + b;
		case '-' : return a - b;
		case '*' : return a * b;
		case '/' : return a / b;
	}
	return 0;
}

void solve(){
	string s;
	cin >> s;
	stack<long long> st1;
	stack<char> st2;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '('){
			st2.push(s[i]);
		}
		else if(s[i] >= '0' && s[i] <= '9'){
			long long num = 0;
			while(s[i] >= '0' && s[i] <= '9'){
				num = num * 10 + (s[i] - '0');
				i++;
			}
			st1.push(num);
			i--;
		}
		else if (s[i] == ')') {
            while (!st2.empty() && st2.top() != '(') {
                long long val2 = st1.top(); st1.pop();
                long long val1 = st1.top(); st1.pop();
                char op = st2.top(); st2.pop();
                st1.push(compute(val1, val2, op));
            }
            if (!st2.empty()) st2.pop();
        }
        else{
        	while (!st2.empty() && priority(st2.top()) >= priority(s[i])) {
                long long val2 = st1.top(); st1.pop();
                long long val1 = st1.top(); st1.pop();
                char op = st2.top(); st2.pop();
                st1.push(compute(val1, val2, op));
            }
            st2.push(s[i]);
		}
	}
	while(!st2.empty()){
		long long val2 = st1.top(); st1.pop();
		long long val1 = st1.top(); st1.pop();
		char op = st2.top(); st2.pop();
		st1.push(compute(val1, val2, op));
	}
	cout << st1.top() << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}