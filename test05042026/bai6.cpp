#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> lucky;
void generate(ll curr){
	if(curr > 10000000000LL) return;
	if(curr > 0) lucky.push_back(curr);
	generate(curr * 10 + 4);
	generate(curr * 10 + 7);
}
int main (){
	generate(0);
	sort(lucky.begin(), lucky.end());
	ll a, b;
	cin >> a >> b;
	ll sum  = 0;
	ll curr = a;
	for(ll num : lucky){
		if(num >= curr){
			ll count = min(b, num) - curr + 1;
			sum += count * num;
			curr = num + 1;
		}
		if(curr > b) break;
	}
	cout << sum << endl;
	return 0;
}