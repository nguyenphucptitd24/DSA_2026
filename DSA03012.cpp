#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		int cnt[26] = {0};
		int max_f = 0;
		for(int i = 0; i < n; i++){
			cnt[(s[i] - 'a')]++;
			if(cnt[(s[i] - 'a')] > max_f){
				max_f =  cnt[(s[i] - 'a')];
			}
		}
		if(max_f <= (n + 1) / 2){
			cout << "1\n";
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}