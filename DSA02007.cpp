#include<bits/stdc++.h>
using namespace std;
string s;
string res;
void backtrack(int pos, int k){
	if(s > res) res= s;
	if(k == 0 || pos == s.length()){
		return;
	}
	char max_val = s[pos];
	for (int i = pos + 1; i < s.length(); i++) {
    	if (s[i] > max_val) max_val = s[i];
	}	
	if(max_val > s[pos]){
		for(int i = pos + 1; i < s.length(); i++){
			if(s[i] == max_val){
				swap(s[pos], s[i]);
				backtrack(pos + 1, k - 1);
				swap(s[pos], s[i]);
			}
		}
	}
	else{
		backtrack(pos + 1, k);
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		cin >> s;
		res = s;
		backtrack(0, k);
		cout << res << endl;
	}
	return 0;
}