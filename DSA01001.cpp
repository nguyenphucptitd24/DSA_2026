#include<bits/stdc++.h>
using namespace std;
void solve(){
	cin.ignore();
	string s;
	cin >> s;
	int n = s.length();
	int i = n - 1;
	while(i >= 0){
		if(s[i] == '0'){
			s[i] = '1';
			break;
		}
		else{
			s[i] = '0';
		}
		i--;
	}
	cout << s << endl;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}