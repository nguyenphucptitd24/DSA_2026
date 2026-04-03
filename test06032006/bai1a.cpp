#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<string> a;
set<string> result_set;
void backtrack(int index, int count, string current_str){
	if(count == k){
		result_set.insert(current_str);
		return;
	}
	if(index == n) return;
	backtrack(index + 1, count + 1, current_str + a[index]);
	backtrack(index + 1, count, current_str);
}
int main (){
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}  
	backtrack(0,0, "");
	for(const string &s : result_set){
		cout << s << "\n";
	}
	return 0;
}