#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxArea(const vector<int> &h){
	int n = h.size();
	stack<int> s;
	ll max_a = 0;
	int i = 0;
	while(i < n){
		if(s.empty() || h[s.top()] <= h[i]){
			s.push(i++);
		}
		else{
			int tp = s.top();
			s.pop();
			ll area = (ll)h[tp] * (s.empty() ? i : i - s.top() - 1);
			max_a = max(max_a, area);
		}
	}
	while(!s.empty()){
		int tp = s.top();
		s.pop();
		ll area = (ll)h[tp] * (s.empty() ? i : i - s.top() - 1);
		max_a = max(max_a, area);
	}
	return max_a;
}
int main (){
	int m, n;
	if(!(cin >> m >> n)) return 0;
	vector<int> yellow(n), blue(n);
	for(int i = 0; i < n; i++){
		cin >> yellow[i];
		blue[i] = m - yellow[i];
	}
	cout << max(maxArea(yellow), maxArea(blue)) << endl;
	return 0;
}